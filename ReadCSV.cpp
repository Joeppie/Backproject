
#include "ReadCSV.h"
#include "thirdparty/csv.h"

std::vector<std::shared_ptr<Image>> ReadImageCsv(std::string fileName)
{

    std::vector<std::shared_ptr<Image>> images;

    //Declare a CSV file format consisting of 12 fields, load in filename.
    io::CSVReader<12> in(fileName);

    //Read in a CSV, note; the order of the headers must match the actual read_row statement;
    //actual in-file order is irrelevant; the file must however have a header.
    in.read_header(io::ignore_extra_column, "filename", "width", "height", "focal_length", "principal_x", "principal_y",
                   "x", "y", "z", "r_x", "r_y", "r_z");

    bool succesful_read;
    do
    {
        std::shared_ptr<Image> image(new Image); //Pointer wrapped by the shared_ptr object.

        //Variables that are populated by values from the CSV.
        std::string fileName;
        int width, height;
        double focal_length;
        Point principalPoint;
        vector rotation(3);
        vector translation(3);

        //The line below passes in the variables above
        succesful_read = in.read_row(fileName, width, height, focal_length,
                                     principalPoint.x, principalPoint.y,
                                     translation[0], translation[1], translation[2],
                                     rotation[0], rotation[1], rotation[2]);

        //If read succesfully, then fully populate the Image object and its IO,EO and add to list to be returned.
        if (succesful_read)
        {
            //Instantiate the image, set image properties first,
            //then, before adding IO and EO, fully initialize them, otherwise image will complain about
            //having been assigned invalid parameters.
            image->set_fileName(fileName);
            image->set_width(width);
            image->set_height(height);

            auto io = std::shared_ptr<InteriorOrientation>(new InteriorOrientation);
            io->set_focalLength(focal_length);
            io->set_principalPoint(principalPoint);
            image->set_IO(io);

            auto eo = (std::shared_ptr<ExteriorOrientation>(new ExteriorOrientation));

            eo->set_rotation(rotation);
            eo->set_translation(translation);
            image->set_EO(eo); //set this last, since image validates the principal point is inside image.

            images.push_back(image);
        }
    }
    while (succesful_read);


    return images;
}
