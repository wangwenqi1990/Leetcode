class Solution {
public:
    // Harsh-table: title + location index
    string encode(string longUrl) {
        url.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(url.size() - 1);
    }

    string decode(string shortUrl) {
        auto pos = shortUrl.find_last_of("/");
        return url[stoi(shortUrl.substr(pos + 1))];
    }
    
private:
    vector<string> url;
};


class Solution {
public:
    // each encoder has fiexed length, good for large number of strings
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }

    string encode(string longUrl) {
        if (long2short.count(longUrl)) {
            return "http://tinyurl.com/" + long2short[longUrl];
        }
        int idx = 0;
        // find a 6 digits string to represents the encoder, repeat sampling till a non-repeated key.
        string randStr;for (int i = 0; i < 6; ++i) randStr.push_back(dict[rand() % 62]);
        while (short2long.count(randStr)) {randStr[idx] = dict[rand() % 62];idx = (idx + 1) % 5;}
        // build mapping
        short2long[randStr] = longUrl;long2short[longUrl] = randStr;
        return "http://tinyurl.com/" + randStr;
    }

    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randStr) ? short2long[randStr] : shortUrl;
    }
    
private:
    unordered_map<string, string> short2long, long2short;
    string dict;
};