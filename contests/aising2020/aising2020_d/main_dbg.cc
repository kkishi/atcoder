#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

map<ll, vector<ll>> mods_cache_global;
const vector<ll>& getModsGlobal(ll mod) {
  mods_cache_global[mod] = {42};
  return mods_cache_global[mod];
};

int main() {
  dbg(getModsGlobal(3).size());

  map<ll, vector<ll>> mods_cache;
  function<const vector<ll>&(ll)> getMods = [&](ll mod) -> const vector<ll>& {
    mods_cache[mod] = {42};
    return mods_cache[mod];
  };

  dbg(getMods(3).size());
  getMods(3);
  dbg(mods_cache[3].size());
}
