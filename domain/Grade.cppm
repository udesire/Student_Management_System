export module TeachingTask;
import std;
export class Grade {
public:
    // 核心业务逻辑方法：
    bool isPass();                                         // 是否及格
    string getGradeLevel();                                // 成绩等级
    void updateGrade(float newScore, string newComment);   // 更新成绩
private:
    float score;
    string comment;
    string dateRecorded;
    StudentRole* student;
    TeachingTask* task;
};
            //删掉，这应该是领域层的工作
            //bool createCourse(Course* course);                     // 创建课程,同时设置选课时间，
            //bool publishTeachingTask(TaskInfo taskInfo);           // 发布教学任务
