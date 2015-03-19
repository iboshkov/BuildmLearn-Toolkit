/*
  Copyright (c) 2012, BuildmLearn Contributors listed at http://buildmlearn.org/people/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of the BuildmLearn nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "templates/videocollection/videocollectionsimulator.h"

#include "core/templatecore.h"
#include "templates/videocollection/videocollectioneditor.h"
#include "templates/videocollection/videocollectionitem.h"
#include "definitions/definitions.h"
#include "miscellaneous/application.h"
#include "miscellaneous/skinfactory.h"
#include <QtWebView/QtWebView>
#include <QMessageBox>

VideoCollectionSimulator::VideoCollectionSimulator(TemplateCore *core, QWidget *parent)
  : TemplateSimulator(core, parent),
    m_ui(new Ui::VideoCollectionSimulator) {
  m_ui->setupUi(this);

  QFont caption_font = m_ui->m_lblHeading->font();
  caption_font.setPointSize(caption_font.pointSize() + SIMULATOR_HEADING_SIZE_INCREASE);
  m_ui->m_lblHeading->setFont(caption_font);

  connect(m_ui->m_btnStart, SIGNAL(clicked()), this, SLOT(start()));
  connect(m_ui->m_btnRestart, SIGNAL(clicked()), this, SLOT(restart()));
}

VideoCollectionSimulator::~VideoCollectionSimulator() {
  qDebug("Destroying VideoCollectionSimulator instance.");

  delete m_ui;
}

bool VideoCollectionSimulator::startSimulation() {
	VideoCollectionEditor *editor = static_cast<VideoCollectionEditor*>(core()->editor());
	QString html = "<html><head><style>* {color: white;}</style></head><body>";
	QList<QString> urls;
	urls.append("http://www.dailymotion.com/embed/video/x33duc");
	urls.append("https://www.youtube.com/embed/kpCJyQ2usJ4");
	QString embed1 = "<iframe width=\"" + QString::number(SIMULATOR_CONTENTS_WIDTH - SIMULATOR_CONTENTS_OFFSET_X) + "\" height=\"315\" src=\"%1\" frameborder=\"0\" allowfullscreen></iframe><hr />";
	QWebView* web = m_ui->webView;
	for (int i = 0; i < 2; i++)
	{
		html += "<b>Name:</b> The Beauty of Algebra<br/>";
		html += "<b>Description:</b> Why the abstraction of mathematics is so fundamental.";
		html += embed1.arg(urls[i]);
	}
	std::string htm = html.toStdString();
	const char* arr = htm.c_str();
	html += "</body></html>";
	
	web->setHtml(html);
//   if (!editor->canGenerateApplications()) {
//     // There are no active questions or quiz does not
//     // containt its name or author name.
//     return false;
//   }
// 
//   // Remove existing flash cards.
//   while (m_ui->m_phoneWidget->count() > 3) {	
//     QWidget *question_widget = m_ui->m_phoneWidget->widget(2);
// 
//     m_ui->m_phoneWidget->removeWidget(question_widget);
//     question_widget->deleteLater();
//   }
// 
//   // Load the questions, setup the quiz and start it.
	m_ui->m_btnStart->setEnabled(true);
//   m_ui->m_lblAuthor->setText(editor->m_ui->m_txtAuthor->lineEdit()->text());
//   m_ui->m_lblHeading->setText(editor->m_ui->m_txtName->lineEdit()->text());
// 
//   int question_number = 1;
//   QList<VideoCollectionQuestion> questions = editor->activeQuestions();
// 
//   foreach (const VideoCollectionQuestion &question, questions) {
//     VideoCollectionItem *item = new VideoCollectionItem(m_ui->m_phoneWidget);
// 
//     connect(item, SIGNAL(nextCardRequested()), this, SLOT(moveToNextCard()));
//     connect(item, SIGNAL(previousCardRequested()), this, SLOT(moveToPreviousCard()));
// 
//     item->setQuestion(question, question_number++, questions.size());
//     m_ui->m_phoneWidget->insertWidget(m_ui->m_phoneWidget->count() - 1, item);
//   }
// 
//   // Go to "start" page and begin.
	m_ui->m_phoneWidget->setCurrentIndex(0);
	return true;
}

bool VideoCollectionSimulator::stopSimulation() {
  m_ui->m_phoneWidget->setCurrentIndex(1);

  emit canGoBackChanged(false);

  return true;
}

bool VideoCollectionSimulator::goBack() {
  return false;
}

void VideoCollectionSimulator::start() {
  moveToNextCard();
}

void VideoCollectionSimulator::restart() {
  //m_ui->m_phoneWidget->setCurrentIndex(1);
}

void VideoCollectionSimulator::moveToNextCard() {
//   int current_index = m_ui->m_phoneWidget->currentIndex();
// 
//   if (current_index < m_ui->m_phoneWidget->count() - 2) {
//     // We are not on the last flash card.
//     static_cast<VideoCollectionItem*>(m_ui->m_phoneWidget->widget(current_index + 1))->reset();
//   }
// 
//   m_ui->m_phoneWidget->setCurrentIndex(current_index + 1);
}

void VideoCollectionSimulator::moveToPreviousCard() {
//   int current_index = m_ui->m_phoneWidget->currentIndex();
// 
//   if (current_index > 1) {
//     // We are not on the first flash card.
//     static_cast<VideoCollectionItem*>(m_ui->m_phoneWidget->widget(current_index - 1))->reset();
//   }
// 
//   m_ui->m_phoneWidget->setCurrentIndex(current_index - 1);
}
