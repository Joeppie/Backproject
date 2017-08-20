//
// Created by joep on 8/20/17.
//
#include "ContextOperation.h"

ContextOperation::ContextOperation() {
  Context::operations.push_back(std::shared_ptr<ContextOperation>(this));
}
