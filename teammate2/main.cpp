#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFontDialog>
#include <QColorDialog>
#include <QPalette>
#include <QFont>

// 定義主視窗類別，繼承自 QWidget
class MainWidget : public QWidget {
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 建立 QTabWidget 作為選項卡框架
        QTabWidget *tabWidget = new QTabWidget(this);

        // =========== 建立四個選項卡（隊長和三位組員） ===========
        // 建立隊長頁面
        QWidget *captainPage = createCaptainPage();
        tabWidget->addTab(captainPage, "隊長頁");

        // 建立組員 1 頁面（修改隊長頁面文字顏色）
        QWidget *member1Page = createMember1Page();
        tabWidget->addTab(member1Page, "組員1 - 改文字顏色");

        // 建立組員 2 頁面（修改隊長頁面文字樣式）
        QWidget *member2Page = createMember2Page();
        tabWidget->addTab(member2Page, "組員2 - 改文字樣式");

        // 建立組員 3 頁面（僅顯示）
        QWidget *member3Page = createMember3Page();
        tabWidget->addTab(member3Page, "組員3 - 顯示頁面");

        // 設定主佈局，將 QTabWidget 添加到主視窗中
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(tabWidget);
        setLayout(mainLayout);

        // 設定視窗標題和尺寸
        setWindowTitle("Qt 協作專案");
        resize(500, 400);
    }

private:
    QLabel *captainLabel; // 將隊長標籤定義為成員變數
    QLabel *member1Label; // 將組員1標籤定義為成員變數
    QLabel *member2Label; // 將組員2標籤定義為成員變數
    QLabel *member3Label; // 將組員3標籤定義為成員變數

    // 建立隊長頁（Captain Page）
    QWidget* createCaptainPage() {
        QWidget *captainPage = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(captainPage);

        // 隊長的姓名與學號，與組員一致格式
        captainLabel = new QLabel("隊長：莊捷森  學號：50915109", captainPage); // 使用成員變數
        layout->addWidget(captainLabel);

        // 添加組員姓名和學號標籤
        member1Label = new QLabel("組員1：翁浩宸  學號：50915124", captainPage);
        member2Label = new QLabel("組員2：鍾秉浩  學號：41243157", captainPage);
        member3Label = new QLabel("組員3：郭廷威  學號：41243232", captainPage);
        layout->addWidget(member1Label);
        layout->addWidget(member2Label);
        layout->addWidget(member3Label);

        return captainPage;
    }

    // 建立組員 1 頁面（修改隊長頁面文字顏色）
    QWidget* createMember1Page() {
        QWidget *memberPage = new QWidget(this);

        return memberPage;
    }

    // 建立組員 2 頁面（修改隊長頁面文字樣式）
    QWidget* createMember2Page() {
        QWidget *memberPage = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(memberPage);

        // 建立按鈕用於選擇字體樣式
        QPushButton *changeFontButton = new QPushButton("選擇文字樣式", memberPage);
        layout->addWidget(changeFontButton);

        // 連接按鈕點擊訊號到槽函數
        connect(changeFontButton, &QPushButton::clicked, this, &MainWidget::changeTextFont);

        memberPage->setLayout(layout);
        return memberPage;
    }

    // 建立組員 3 頁面（僅顯示）
    QWidget* createMember3Page() {
 QWidget *memberPage = new QWidget(this);
        return memberPage;
    }

private slots:
    // 槽函數：變更隊長及組員標籤文字顏色
    void changeTextColor() {
        QColor color = QColorDialog::getColor(Qt::white, this);
        if (color.isValid()) {
            // 設定隊長的顏色
            QPalette captainPalette = captainLabel->palette();
            captainPalette.setColor(QPalette::WindowText, color);
            captainLabel->setPalette(captainPalette);

            // 設定組員的顏色
            QPalette memberPalette;
            memberPalette.setColor(QPalette::WindowText, color);
            member1Label->setPalette(memberPalette);
            member2Label->setPalette(memberPalette);
            member3Label->setPalette(memberPalette);
        }
    }

    // 槽函數：變更隊長及組員標籤文字樣式
    void changeTextFont() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, this);
        if (ok) {
            // 設定隊長的字體
            captainLabel->setFont(font);

            // 設定組員的字體
            member1Label->setFont(font);
            member2Label->setFont(font);
            member3Label->setFont(font);
        }
    }
};

// 主程式進入點
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 建立主視窗物件
    MainWidget mainWidget;
    mainWidget.show();

    return app.exec();
}

#include "main.moc"
