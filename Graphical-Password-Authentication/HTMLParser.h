#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <string>
#include <vector>
#include <QString>

QString GetHTML(QString topic, bool isSetup);
std::vector<QString> getImageAddresses(QString html);
std::vector<QString> getImageAddresses(QString html, bool isSetup);
std::vector<QString> setUpTopics();
QString selectTopic(std::vector<QString> topicVector);

#endif // HTMLPARSER_H
