export module TaskInfo;

import std;
export class TaskInfo{
public:
    bool isValid();  // 验证所有字段非空且有效
private:
    string courseId;
    string teacherId;
    string semester;
    string timeSlot;
    string classroom;
    int maxCapacity;
};
