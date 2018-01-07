#include "../../include/rapidjson/prettywriter.h"
#include "../../include/model/ReturnModel.h"

using namespace rapidjson;

ReturnModel::ReturnModel(int status) 
{
    this->status = status;
}

void ReturnModel::GetOutput(std::string * output, BaseModel * model)
{
    StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
    writer.StartObject();
    writer.String("status");
    writer.Int(this->status);
    if (model != NULL) {
        writer.String("object");
        model->Serialize(writer);
    }
    writer.EndObject();
    *output = buffer.GetString();
}
