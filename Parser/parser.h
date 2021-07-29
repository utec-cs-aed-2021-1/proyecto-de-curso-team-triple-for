#include <nlohmann/json.hpp>
#include <string.h>

using json = nlohmann::json;
using namespace std;

json getJsonFromFile(string fileName);
