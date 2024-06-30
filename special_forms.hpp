#ifndef SPECIAL_FORMS_HPP__
#define SPECIAL_FORMS_HPP__

#include "SyntaxTree.hpp"
#include "env.hpp"
#include "eval.hpp"
#include <unordered_set>

using SyntaxTree_::SyntaxTree;

extern std::unordered_set<Symbol> specialForms;

SyntaxTree handleSpecialForms(const std::list<SyntaxTree> & items, Frame & env);

#endif