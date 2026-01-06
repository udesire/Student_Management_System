export module TeachingTask;
import std;

export class Course {
public:
    Course(string courseId, string name, float credits,long long enrollStart, long long enrollEnd);
    // 核心业务逻辑方法：
    string getInfo();                     // 获取课程详情
    bool canEnroll();                    //是否可选课（是否在选课时间内）

private:
    string courseId;
    string name;
    float credits;  //课程对应学分
    std::time_t enrollStart;  // 选课开始时间戳
    td::time_t enrollEnd;    // 选课结束时间戳

};

Course::Course(string cId, string name, float credits,long long enrollStart, long long enrollEnd)
:courseId(cId),name(name),credits(credits),enrollEnd(enrollEnd),enrollStart(enrollStart)
{}

string Course::getInfo(){
   auto timeToString = [](long long ts) -> std::string {
        if (ts <= 0) return "未设置";
        std::time_t t = static_cast<std::time_t>(ts);

        std::tm* tm = std::localtime(&t);
        if (!tm) return "时间错误";

        std::ostringstream oss;
        oss << std::put_time(tm, "%m月%d日");
        return oss.str();
    };

    return std::format("ID:{} name:{} credits:{} 选课时间：{}  至  {}",
    courseId,name,credits,timeToString(enrollStart),timeToString(enrollEnd));
}

bool Course::canEnroll(std::time_t currentTime){
    return currentTime >= enrollStart && currentTime <= enrollEnd;
}
