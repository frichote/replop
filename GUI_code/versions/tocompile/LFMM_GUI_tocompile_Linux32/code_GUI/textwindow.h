#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QTextEdit>

class TextWindow : public QTextEdit
{
    Q_OBJECT

public:
    TextWindow(QWidget *parent = 0);
    ~TextWindow();

	QString currentFile()
	{
		return file;
	}

	bool loadFile(const QString &fileName);

private:
	void setCurrentFile(const QString &fileName);
	QString file;
};

#endif // TEXTWINDOW_H
