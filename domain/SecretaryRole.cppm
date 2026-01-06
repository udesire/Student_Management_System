export module SecretaryRole;
import std;
import Role;
import TaskInfo;

export class SecretaryRole: public Role{
public:
    SecretaryRole(string id,string name,string gender, string department);
    virtual string getRoleType()override;

private:

    string department;      // 所属院系
};

SecretaryRole::SecretaryRole(string id,string name,string gender, string department)
:Role(id,name,gender),department(department)
{}
string SecretaryRole::getRoleType(){
    return std::format("secretary");
}

