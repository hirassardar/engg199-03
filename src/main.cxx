
// Qt header files
#include <QApplication>

// Our header files
#include "ui.h"

void main()
{
	// Create the Qt application
	int argc = 0;
	QApplication app(argc, 0);

	// Create the user interface
	ui myui;

	// Start the Qt application event loop
	app.exec();
}
