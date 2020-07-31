#include <cpprest/http_client.h>
#include <iostream>

int main(int argc, char** argv)
{
    web::http::client::http_client_config config;
    config.set_validate_certificates(true);

    web::http::client::http_client client(utility::conversions::to_string_t("https://www.google.com:443/"), config);

    std::string sHostHeaderValue = utility::conversions::to_utf8string(client.base_uri().host());
    const int port = client.base_uri().port();
    if (port > 0)
    {
        sHostHeaderValue.append(":");
        sHostHeaderValue.append(std::to_string(port));
    }

    web::http::http_request request(web::http::methods::HEAD);
    request.headers().add(utility::conversions::to_string_t("Host"), utility::conversions::to_string_t(sHostHeaderValue));

    try
    {
        auto requestTask = pplx::create_task(client.request(request));
        auto response = requestTask.get();

        if (response.status_code() != web::http::status_codes::OK)
        {
            std::cout << "Encountered an error while performing request. Code (" << response.status_code() << ")." << std::endl;
            return 1;
        }

        std::cout << "Request successful." << std::endl;
    }
    catch (const web::http::http_exception& e)
    {
        std::cout << "Encountered an error while performing request. " << e.what() << std::endl;
        return 2;
    }

    return 0;
}

