#include "HTMLParser.h"
#include <vector>

std::vector<std::string> setUpTopics() {
    std::vector<std::string> topicVector;
    topicVector.push_back("cat");
    topicVector.push_back("dog");
    topicVector.push_back("flower");
    topicVector.push_back("traffic light");

    return topicVector;
}

std::string selectTopic(std::vector<std::string> topicVector) {
    srand(time(NULL));
    int randomIndex = rand() % topicVector.size();
    std::string topic = topicVector[randomIndex];
    return topic;
}

std::string GetHTML() {

}


