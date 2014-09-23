/*
 * TranslationUnit.hpp
 *
 * Copyright (C) 2009-12 by RStudio, Inc.
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef SESSION_MODULES_CLANG_TRANSLATION_UNIT_HPP
#define SESSION_MODULES_CLANG_TRANSLATION_UNIT_HPP

#include <boost/noncopyable.hpp>

#include "Clang.hpp"
#include "CodeCompleteResults.hpp"

namespace session {
namespace modules {      
namespace clang {

class TranslationUnit
{
public:
   TranslationUnit()
      : tu_(NULL)
   {
   }

   TranslationUnit(const std::string& filename, CXTranslationUnit tu)
      : filename_(filename), tu_(tu)
   {
   }

   // translation units are managed and disposed by the SourceIndex, so
   // so instances of this class can be freely copied

   operator CXTranslationUnit() const { return tu_; }

   bool empty() const { return ! tu_; }

   CodeCompleteResults codeCompleteAt(unsigned line, unsigned column);

private:
   std::string filename_;
   CXTranslationUnit tu_;
};

} // namespace clang
} // namepace handlers
} // namesapce session

#endif // SESSION_MODULES_CLANG_TRANSLATION_UNIT_HPP
