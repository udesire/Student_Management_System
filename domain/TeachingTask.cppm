export module TeachingTask;
import std;
export class TeachingTask{
public:
    TeachingTask(string taskId,string semester,std::time_t enrollStart,
    std::time_t enrollEnd,int maxCapacity);
// 核心业务逻辑方法：
    bool addStudent(StudentRole* student);     // 添加学生
    bool removeStudent(string studentId);      // 移除学生
    bool assignTeacher(TeacherRole* teacher);  // 分配教师
    bool hasTimeConflict(TeachingTask* other); // 时间冲突检查
    bool isFull();                             // 容量检查
};
private:
    string taskId;
    string semester;        // 学期
    std::time_t enrollStart;  // 选课开始时间戳
    std::time_t enrollEnd;    // 选课结束时间戳
    int maxCapacity;    //最大选课人数
    int currentEnrolled; //已选人数
    //关联
    string courseId;
    string teacherId;
    vector<string> enrolledstudents_id;
};
TeachingTask TeachingTask(string taskId,string semester,std::time_t enrollStart,
std::time_t enrollEnd,int max)
:taskId(taskId),semester(semester),enrollStart(enrollStart),enrollEnd(enrollEnd),maxCapacity(max)
{}
