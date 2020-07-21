#include "network.h"

using namespace little_helper;

std::string network::guessFileName(const std::string& url)
{
#ifdef LH_WINDOWS_PLATFORM
    URL_COMPONENTSA urlComp;
	ZeroMemory(&urlComp, sizeof(urlComp));
	urlComp.dwStructSize = sizeof(urlComp);
	urlComp.dwUrlPathLength = (DWORD)-1;
	urlComp.dwExtraInfoLength = (DWORD)-1;

	if (!WinHttpCrackUrlA(url.c_str(), url.size(), 0, &urlComp))
	{
		return std::string();
	}

	if (wcslen(urlComp.lpszExtraInfo) > 0)
	{
		auto ret = strstr(urlComp.lpszUrlPath, urlComp.lpszExtraInfo);
		if (ret != nullptr)
			*ret = '\0';
	}

	std::filesystem::path url_path = urlComp.lpszUrlPath;
	if (url_path.has_filename())
		return url_path.filename();
	else
		return std::string();
#else

#endif
}

std::wstring network::guessFileName(const std::wstring& url)
{
#ifdef LH_WINDOWS_PLATFORM
    URL_COMPONENTSW urlComp;
	ZeroMemory(&urlComp, sizeof(urlComp));
	urlComp.dwStructSize = sizeof(urlComp);
	urlComp.dwUrlPathLength = (DWORD)-1;
	urlComp.dwExtraInfoLength = (DWORD)-1;

	if (!WinHttpCrackUrlW(url.c_str(), url.size(), 0, &urlComp))
	{
		return std::wstring();
	}

	if (wcslen(urlComp.lpszExtraInfo) > 0)
	{
		auto ret = wcsstr(urlComp.lpszUrlPath, urlComp.lpszExtraInfo);
		if (ret != nullptr)
			*ret = L'\0';
	}

	std::filesystem::path url_path = urlComp.lpszUrlPath;
	if (url_path.has_filename())
		return url_path.filename();
	else
		return std::wstring();
#else

#endif
}

std::string network::getUrlParamValue(const std::string& url, const std::string& param)
{
#ifdef LH_WINDOWS_PLATFORM
	URL_COMPONENTSA urlComp;
	ZeroMemory(&urlComp, sizeof(urlComp));
	urlComp.dwStructSize = sizeof(urlComp);
	urlComp.dwUrlPathLength = (DWORD)-1;
	urlComp.dwExtraInfoLength = (DWORD)-1;

	if (!WinHttpCrackUrlA(url.c_str(), url.size(), 0, &urlComp))
		return std::string();

	if (wcslen(urlComp.lpszExtraInfo) <= 0)
		return std::string();

	std::smatch m;
	std::regex r(std::string(param) + "=([^&]*)(&|$)");
	if (std::regex_search(url, m, r))
		return m[1].str();
	else
		return std::string();
#else

#endif
}

std::wstring network::getUrlParamValue(const std::wstring& url, const std::wstring& param)
{
#ifdef LH_WINDOWS_PLATFORM
	URL_COMPONENTSW urlComp;
	ZeroMemory(&urlComp, sizeof(urlComp));
	urlComp.dwStructSize = sizeof(urlComp);
	urlComp.dwUrlPathLength = (DWORD)-1;
	urlComp.dwExtraInfoLength = (DWORD)-1;

	if (!WinHttpCrackUrlW(url.c_str(), url.size(), 0, &urlComp))
		return std::wstring();

	if (wcslen(urlComp.lpszExtraInfo) <= 0)
		return std::wstring();

	std::wsmatch m;
	std::wregex r(std::wstring(param) + L"=([^&]*)(&|$)");
	if (std::regex_search(url, m, r))
		return m[1].str();
	else
		return std::swtring();
#else

#endif
}
