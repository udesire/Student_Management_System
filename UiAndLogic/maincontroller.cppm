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
    StudentController* getStudentController();
    TeacherController* getTeacherController();
    SecretaryController* getSecretaryController();
    CourseController* getCourseController();
    GradeController* getGradeController();
    void initialize();

    // 添加执行学生和执行老师的方法
    mainController->executeTeacherCommand(choice, teacherId);

    void

private:
    std::unique_ptr<StudentController> studentController;
    std::unique_ptr<TeacherController> teacherController;
    std::unique_ptr<SecretaryController> secretaryController;
    std::unique_ptr<CourseController> courseController;
    std::unique_ptr<GradeController> gradeController;
};

MainController::MainController() {
    initialize();
}

// 智能指针构造函数参数添加 +++++
void MainController::initialize() {
// 创建数据库管理器
    DataBroker* db = new DataBroker();
    StudentBroker* sBroker = new StudentBroker(db);
    TeacherBroker* tBroker = new TeacherBroker(db);
    TeachingTaskBroker* ttBroker = new TeachingTaskBroker(db);
    CourseBroker* cBroker = new CourseBroker(db);



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

