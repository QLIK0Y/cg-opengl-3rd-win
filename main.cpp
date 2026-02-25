
#include "QApp.h"

QRunnable bg_color_runnable();
QRunnable point_runnable();

int demo_main(QRunnable runnable ) {
	QApp app(runnable);
	if (int ret = app.Init(); ret != 0) {
		return ret;
	}
	return app.Run();
}

int main() {
	//return demo_main(bg_color_runnable());
	return demo_main(point_runnable());
}

