#include "BaseModel.h"

class BBUserModel: public BaseModel
{
    public:
        std::string name;       // 姓名
        std::string nickname;   // 昵称
        int sex;                // 性别: 0-female 1-male 2-人妖
        
        BBUserModel(long int user_id);
	    BBUserModel(long int user_id, std::string name, std::string nickname, int sex);
	    BBUserModel(std::string name, std::string nickname, int sex);
        BBUserModel(Value& value);

        // template <typename Writer>
        // void Serialize(Writer & writer) const;
	    virtual void Serialize(PrettyWriter<StringBuffer>& writer) const; 

        friend std::ostream& operator<<(std::ostream& os, BBUserModel& model);

        long int getUserId();

    protected:
        long int user_id;       // 用户id
};

