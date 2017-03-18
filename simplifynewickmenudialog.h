#ifndef TOOLSIMPLIFYNEWICKMENUDIALOG_H
#define TOOLSIMPLIFYNEWICKMENUDIALOG_H

#include "menudialog.h"

namespace ribi {

///GUI independent ToolSimplifyNewick menu dialog
struct ToolSimplifyNewickMenuDialog final : public MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
};

} //~namespace ribi

#endif // TOOLSIMPLIFYNEWICKMENUDIALOG_H
