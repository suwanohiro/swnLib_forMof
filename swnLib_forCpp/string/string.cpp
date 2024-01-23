#include "string.hpp"

using namespace swn;

string swn::string::__createPadding(int maxLength, const string& fillString)
{
    if (length() > maxLength) return *this;

    std::string padding = "";
    while (padding.length() + length() < maxLength) {
        padding += fillString;
    }
    return padding.substr(0, maxLength - length());
}

string string::padStart(int maxLength, const string& fillString)
{
    // 格納されている文字数が最大文字数以上ならば処理せずそのまま返す
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return padding + *this;
}

string swn::string::padEnd(int maxLength, const string& fillString)
{
    // 格納されている文字数が最大文字数以上ならば処理せずそのまま返す
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return *this + padding;
}

string swn::string::trim()
{
    // 左側の空白を削除
    auto left_trimmed = this->find_first_not_of(" \t\r\n");
    left_trimmed = (left_trimmed == std::string::npos) ? 0 : left_trimmed;

    // 右側の空白を削除
    auto right_trimmed = this->find_last_not_of(" \t\r\n");
    right_trimmed = (right_trimmed == std::string::npos) ? this->length() - 1 : right_trimmed;

    // 結果を返す
    return this->substr(left_trimmed, right_trimmed - left_trimmed + 1);
}

std::vector<string> swn::string::split(const string& splitter)
{
    std::vector<string> result;

    size_t start = 0;
    size_t end = this->find(splitter);

    while (end != std::string::npos) {
        result.push_back(this->substr(start, end - start));
        start = end + splitter.length();
        end = this->find(splitter, start);
    }

    result.push_back(this->substr(start));

    return result;
}
