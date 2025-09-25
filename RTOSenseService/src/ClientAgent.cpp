#include "ClientAgent.h"

bool ClientAgent::sendToClient(const std::string &jsonData)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *headers = nullptr;
    for (const auto &client : clients)
    {
        std::cout << "Sending " << jsonData << " to " << client << std::endl;
        if (!curl) return false;

        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, client.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, jsonData.size());
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 2L);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

        res = curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            std::cout << "Failed to send to client " << client << "; error code - " << res << std::endl;
        }
    }
    return res;
}