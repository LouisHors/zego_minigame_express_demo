//
//  ZegoJson.hpp
//  zegoavkit
//
//  Created by Randy Qiu on 3/22/16.
//  Copyright © 2016 Zego. All rights reserved.
//

#ifndef ZegoJson_h
#define ZegoJson_h

#include <functional>
#include <memory>
#include <string>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <zegomess.h>
#include <zegostream.h>

namespace ZEGO {
namespace BASE {

class CZegoJson {
  public:
    CZegoJson();

    CZegoJson(const char *pContent);

    bool SetNode(rapidjson::Value &value);
    bool SetContent(const char *pContent);
    std::string GetContent();

    bool HasMember(const char *key);
    zego::strutf8 GetString();
    operator bool();
    operator int();
    operator uint32();
    operator uint64();
    operator int64();
    operator double();
    operator zego::strutf8();
    operator std::string();
    operator std::shared_ptr<zego::strutf8>();

    BASE::CZegoJson operator[](const char *key);
    BASE::CZegoJson operator[](uint32 idx);
    uint32 GetSize() const;
    bool IsValid() const;

  private:
    std::shared_ptr<rapidjson::Document> m_pDoc;
    bool m_bValid = false;
};

zego::strutf8 GetStringFromJson(rapidjson::Document &doc);
std::string GetStringFromJsonString(rapidjson::Document &doc);

template <typename T> inline void AddMember(rapidjson::Document &doc, const char *k, T v) {
    if (!k) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, doc.GetAllocator());

    rapidjson::Value value(v);
    doc.AddMember(key, value, doc.GetAllocator());
}

template <> inline void AddMember(rapidjson::Document &doc, const char *k, const char *v) {
    if (!k || !v) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, doc.GetAllocator());

    rapidjson::Value value;
    value.SetString(v, doc.GetAllocator());

    doc.AddMember(key, value, doc.GetAllocator());
}

template <typename T>
inline void AddMember(rapidjson::Value &obj, const char *k, T v,
                      rapidjson::Document::AllocatorType &allocator) {
    if (!k) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, allocator);

    rapidjson::Value value(v);
    obj.AddMember(key, value, allocator);
}

template <>
inline void AddMember(rapidjson::Value &obj, const char *k, const char *v,
                      rapidjson::Document::AllocatorType &allocator) {
    if (!k || !v) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, allocator);

    rapidjson::Value value;
    value.SetString(v, allocator);

    obj.AddMember(key, value, allocator);
}

template <>
inline void AddMember(rapidjson::Value &obj, const char *k, rapidjson::Value *value,
                      rapidjson::Document::AllocatorType &allocator) {
    if (!k || !value) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, allocator);

    obj.AddMember(key, *value, allocator);
}

template <>
inline void AddMember(rapidjson::Value &obj, const char *k, rapidjson::Document *doc,
                      rapidjson::Document::AllocatorType &allocator) {
    if (!k || !doc) {
        return;
    }

    rapidjson::Value key;
    key.SetString(k, allocator);

    obj.AddMember(key, *doc, allocator);
}
} // namespace BASE
} // namespace ZEGO

#endif
