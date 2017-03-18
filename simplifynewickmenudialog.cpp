#include "simplifynewickmenudialog.h"

#include <cassert>
#include <iostream>

#include "newickvector.h"


int ribi::ToolSimplifyNewickMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 0;
  }
  assert(!"TODO");
  return 0;
}

ribi::About ribi::ToolSimplifyNewickMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "SimplifyNewick",
    "tool to randomly simplify Newick phylogenies",
    "the 19th of September 2013",
    "2010-2015",
    "http://www.richelbilderbeek.nl/ToolSimplifyNewick.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("NewickVector version: " + NewickVector::GetVersion());
  return a;
}

ribi::Help ribi::ToolSimplifyNewickMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::ToolSimplifyNewickMenuDialog::GetVersion() const noexcept
{
  return "4.0";
}

std::vector<std::string> ribi::ToolSimplifyNewickMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2010-09-12: version 1.0: initial version",
    "2010-09-16: version 1.1: use of BinaryNewickVector version 1.0, added library version numbers in About screen, added 'What's New?' dialog, added difference in debug and release version",
    "2010-09-16: version 1.2: simplification is frequency dependent. For example: (100,2) will be simplified to (99,2) 50x more often than to (100,1)",
    "2011-05-07: version 2.0: use NewickVector instead of BinaryNewickVector, replace custom about and whats new dialog by QtAboutDialog",
    "2013-09-19: version 3.0: conformized for ProjectRichelBilderbeek",
    "2013-11-05: version 3.1: conformized for ProjectRichelBilderbeekConsole",
    "2015-11-23: version 4.0: moved to own GitHub",
  };
}
