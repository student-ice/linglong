// Thish file is generated by /tools/run-quicktype.sh
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Source.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "linglong/builder/project/helper.hpp"

namespace linglong {
namespace builder {
namespace project {
using nlohmann::json;

struct Source {
std::optional<std::string> commit;
std::optional<std::string> digest;
std::string kind;
std::optional<std::vector<std::string>> patch;
std::optional<std::string> url;
std::optional<std::string> version;
};
}
}
}

// clang-format on