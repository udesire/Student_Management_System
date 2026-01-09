export module maincontroller;

export import :studentcontroller;
export import :teachercontroller;
export import :secretarycontroller;
export import :coursecontroller;
export import :gradecontroller;
export import DataBase;
export import std;

export class MainController {
public:
    MainController();
    // 定义析构函数
    ~MainController();
    StudentController* getStudentController();
    TeacherController* getTeacherController();
    SecretaryController* getSecretaryController();
    CourseController* getCourseController();
    GradeController* getGradeController();
    void initialize();

    // 添加执行学生和执行老师的方法
    void executeTeacherCommand(int choice, const string& teacherId) const;
    void executeStudentCommand(int choice, const string& studentId) const;

private:
    std::unique_ptr<StudentController> studentController;
    std::unique_ptr<TeacherController> teacherController;
    std::unique_ptr<SecretaryController> secretaryController;
    std::unique_ptr<CourseController> courseController;
    std::unique_ptr<GradeController> gradeController;
    CourseBroker* cBroker;
    TeachingTaskBroker* ttBroker;
    TeacherBroker* tBroker;
    StudentBroker* sBroker;
    DataBroker* db;
};
MainController::~MainController()
{
    delete cBroker;
    delete ttBroker;
    delete tBroker;
    delete sBroker;
    delete db;
}

// 执行老师的命令
// print("==================== 教师功能菜单 [{}] ====================\n",teacherId);
// print("1. 查看个人信息\n");
// print("2. 查看授课任务\n");
// print("3. 录入学生成绩\n");
// print("4. 查看任务学生名单\n");
// print("0. 返回主菜单\n");
// print("======================================================================\n");
void MainController::executeTeacherCommand(int choice, const string& teacherId) const {

}

// 执行学生的命令
// print("==================== 学生功能菜单 [{}] ====================\n",studentId);
// print("1. 查看个人信息\n");
// print("2. 查看已选课程/任务\n");
// print("3. 选课\n");
// print("4. 退课\n");
// print("5. 查看成绩/GPA\n");
// print("0. 返回主菜单\n");
// print("======================================================================\n");
void MainController::executeStudentCommand(int choice, const string& studentId) const {

}

MainController::MainController() {
    std::println("正在启动主控制器...");
    initialize();
    std::println("初始化成功");
}

// 智能指针构造函数参数添加 +++++
void MainController::initialize() {
// 创建数据库管理器
    db = new DataBroker();
    sBroker = new StudentBroker(db);
    tBroker = new TeacherBroker(db);
    ttBroker = new TeachingTaskBroker(db);
    cBroker = new CourseBroker(db);



    studentController = std::make_unique<StudentController>(sBroker,cBroker,ttBroker);
    teacherController = std::make_unique<TeacherController>(tBroker,cBroker,ttBroker);
//  暂时删除秘书控制器，老师也可以安排选课，todo：第二次实现这个教学秘书选课的能力
//   secretaryController = std::make_unique<SecretaryController>();
    courseController = std::make_unique<CourseController>(cBroker,ttBroker,sBroker);
    gradeController = std::make_unique<GradeController>(tBroker,sBroker,ttBroker);
}

StudentController* MainController::getStudentController() {
    return studentController.get();
}

TeacherController* MainController::getTeacherController() {
    return teacherController.get();
}

SecretaryController* MainController::getSecretaryController() {
    return secretaryController.get();
}

CourseController* MainController::getCourseController() {
    return courseController.get();
}

GradeController* MainController::getGradeController() {
    return gradeController.get();
}

