#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Browser : public QWidget {
public:
    Browser(QWidget *parent = nullptr) : QWidget(parent) {
        // メインのレイアウト
        QVBoxLayout *layout = new QVBoxLayout(this);

        // タブウィジェットを作成
        tabWidget = new QTabWidget(this);

        // 新規タブを作成
        createNewTab();

        // タブウィジェットをレイアウトに追加
        layout->addWidget(tabWidget);
    }

private:
    QTabWidget *tabWidget;

    void createNewTab() {
        QWidget *tab = new QWidget(this);

        // アドレスバー (QLineEdit)
        QLineEdit *addressBar = new QLineEdit(tab);
        addressBar->setPlaceholderText("Enter URL or search...");
        
        // 「Mitssu」のテキスト表示
        QLabel *label = new QLabel("Mitssu", tab);

        // さらに「検索」ボタンなども追加可能（今回は省略）

        // レイアウト設定
        QVBoxLayout *tabLayout = new QVBoxLayout(tab);
        tabLayout->addWidget(addressBar);
        tabLayout->addWidget(label);

        // タブに追加
        tabWidget->addTab(tab, "New Tab");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // ウィジェットを作成して表示
    Browser browser;
    browser.setWindowTitle("Simple Browser");
    browser.resize(800, 600);
    browser.show();

    return app.exec();
}
