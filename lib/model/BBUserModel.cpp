#include "../../include/model/BBUserModel.h"

BBUserModel::BBUserModel(long int user_id) : user_id(user_id)
{
}

BBUserModel::BBUserModel(long int user_id, std::string name, std::string nickname, int sex) : user_id(user_id), name(name), nickname(nickname), sex(sex)
{
}

BBUserModel::BBUserModel(std::string name, std::string nickname, int sex) : name(name), nickname(nickname), sex(sex)
{
}

BBUserModel::BBUserModel(Value& value)
{
    if (value.IsObject()) {
        if (value.HasMember("user_id"))
            user_id = value["user_id"].GetInt();
        if (value.HasMember("name"))
            name = value["name"].GetString();
        if (value.HasMember("nickname"))
            nickname = value["nickname"].GetString();
        if (value.HasMember("sex"))
            sex = value["sex"].GetInt();
    }
}

long int BBUserModel::getUserId()
{
    return user_id;
}

void BBUserModel::Serialize(PrettyWriter<StringBuffer>& writer) const 
{
    writer.StartObject();
    writer.String("user_id");
    writer.Int(user_id);
    writer.String("sex");
    writer.Int(sex);

#if RAPIDJSON_HAS_STDSTRING
    writer.String("name");
    writer.String(name);
    writer.String("nickname");
    writer.String(nickname);
#else
    writer.String("name");
    writer.String(name.c_str(), static_cast<SizeType>(name.length()));
    writer.String("nickname");
    writer.String(nickname.c_str(), static_cast<SizeType>(nickname.length()));
#endif
    writer.EndObject();
}

std::ostream& operator<<(std::ostream& os, BBUserModel& model)
{
    os<<"(user_id="<<model.getUserId()<<", name="<<model.name<<", nickname="<<model.nickname<<", sex="<<model.sex<<")"<<std::endl;
    return os;
}

