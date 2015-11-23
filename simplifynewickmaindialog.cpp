//---------------------------------------------------------------------------
/*
SimplifyNewick, tool to randomly simplify Newick phylogenies
Copyright (C) 2010-2015 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolSimplifyNewick.htm
//---------------------------------------------------------------------------
#include "simplifynewickmaindialog.h"

#include <iostream>

#include "newick.h"
#include "newickvector.h"

std::string ribi::ToolSimplifyNewickMainDialog::SimplifyNewick(
  const std::string& s,
  const BigInteger& max_complexity)
{
  std::unique_ptr<const NewickVector> n{ new NewickVector(s) };
  while (1)
  {
    const BigInteger complexity = Newick().CalcComplexity(n->Peek());
    if (complexity <= max_complexity) return n->ToStr();
    const std::vector<std::pair<std::vector<int>,int> > v
      = Newick().GetSimplerNewicksFrequencyPairs(n->Peek());
    if (v.empty()) return n->ToStr();
    const int sum = SumSecond(v);

    const int index_chosen = std::rand() % sum;
    //std::clog << "Index chosen: " << index_chosen << '\n';
    int current_sum = 0;
    for (int i=0; ;++i)
    {
      assert(i != boost::numeric_cast<int>(v.size()));
      current_sum+=v[i].second;
      //std::clog << "Index " << i << ", sum: " << current_sum << '\n';
      if (current_sum >= index_chosen)
      {
        //std::clog << "Index " << i << " chosen\n";
        n.reset(new NewickVector(v[i].first));
        break;
      }
    }
  }
}

int ribi::ToolSimplifyNewickMainDialog::SumSecond(
  const std::vector<std::pair<std::vector<int>,int> >& v) noexcept
{
  int sum = 0;
  typedef std::pair<std::vector<int>,int> Pair;
  for(const Pair& p: v)
  {
    sum+=p.second;
  }
  return sum;
}
