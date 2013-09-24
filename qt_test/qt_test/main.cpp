#include "qt_test.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <curl/curl.h>
#include <LoginDialog.h>


size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[])
{
	/*CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "google.com";
    char outfilename[FILENAME_MAX] = "bbb.txt";
    curl = curl_easy_init();
    if (curl) {
        fopen_s(&fp,outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);*/
        /* always cleanup */
        /*curl_easy_cleanup(curl);
        fclose(fp);
    }*/
	QApplication a(argc, argv);
	qt_test w;
	w.show();
	w.setFixedSize(APP_WIDTH,APP_HEIGHT);
	return a.exec();
	/*QString a;
	a="Luca";
	LoginDialog* loginDialog = new LoginDialog(  );
loginDialog->setUsername( a );  // optional
QObject::connect( loginDialog,
                 SIGNAL(acceptLogin(QString&,QString&,int&)),
                 loginDialog,
                 SLOT(slotAcceptUserLogin(QString&,QString&)));
loginDialog->exec();*/
}
