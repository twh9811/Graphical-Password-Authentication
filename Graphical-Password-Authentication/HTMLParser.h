#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <string>
#include <vector>
#include <QString>

QString GetHTML(std::string topic);
std::vector<QString> getImageAddresses(QString html);
std::vector<std::string> setUpTopics();
std::string selectTopic(std::vector<std::string> topicVector);

#endif // HTMLPARSER_H
