#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
  public:
    Variable(std::string var)
        : ASTNode(var)
        {}

    Variable &operator=(const Variable &) = default;

    ~Variable();
    std::string variabl() const { return var; }

  private:
    std::string var;
};