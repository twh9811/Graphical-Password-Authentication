#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <string>
#include <vector>

std::string GetHTML();
std::vector<std::string> setUpTopics();
std::string selectTopic(std::vector<std::string> topicVector);

#endif // HTMLPARSER_H
