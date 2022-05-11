#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <string>
#include "particle.h"
#include <ctime>



namespace Project2 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Постоянные частиц и нормальных условий
	int N;
	double t;
	double N_A = 6.022 * 10e23;
	double r_theor = 10e-6;
	double T = 273;
	double m = 4 * 10e-15;
	double eta = 10e-3;
	double K_b = 1.4 * 10e-23;
	double V_theor = sqrt(( K_b * T) / m);
	double R=K_b*N_A;
	double alpha = 2 * 3.14 * eta * R;
	double tay = m / alpha;
	
	
	
	ofstream fin("Histogram_pazbienia.txt");
	//ofstream fin2("Delta_X_sqr_particles.txt");

	float V_ = 10;

	//для отрисовки
	int del;
	float r = 4;
	particle* mol;
	particle* mol2;
	
	int w_, h_;
	int w_2, h_2;
	int One_Tick = 0;

	double* fract = new double[50000];

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;


		



	public:
  
	public:



		bool flag;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

	private:
	Graphics^ image;
	Graphics^ image2;
	BufferedGraphics^ bufferedGraphics;
	BufferedGraphicsContext^ bufferedGraphicsContext;
	BufferedGraphics^ bufferedGraphics2;
	BufferedGraphicsContext^ bufferedGraphicsContext2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;













	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->panel1->Location = System::Drawing::Point(12, 105);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(721, 212);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"50";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(245, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 58);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Начало";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Число частиц";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// chart1
			// 
			this->chart1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(739, 105);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(355, 448);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			title1->Name = L"Title1";
			title1->Text = L"Число частиц от координаты x для одномерного случая";
			this->chart1->Titles->Add(title1);
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(468, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 58);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Конец";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Location = System::Drawing::Point(12, 323);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(721, 230);
			this->panel2->TabIndex = 6;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(108, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"3";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Число делений";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(675, 33);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 48);
			this->button3->TabIndex = 9;
			this->button3->Text = L"распределение вероятности";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(832, 61);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"500";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(795, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"размерный коэффициент";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			this->chart2->Location = System::Drawing::Point(1100, 323);
			this->chart2->Name = L"chart2";
			series3->ChartArea = L"ChartArea1";
			series3->Name = L"Series1";
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(267, 230);
			this->chart2->TabIndex = 12;
			this->chart2->Text = L"chart2";
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			title2->Name = L"Title1";
			title2->Text = L"<X>";
			this->chart2->Titles->Add(title2);
			this->chart2->Click += gcnew System::EventHandler(this, &MyForm::chart2_Click_1);
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			this->chart3->Location = System::Drawing::Point(1100, 105);
			this->chart3->Name = L"chart3";
			series4->ChartArea = L"ChartArea1";
			series4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series4->Name = L"Series1";
			this->chart3->Series->Add(series4);
			this->chart3->Size = System::Drawing::Size(267, 212);
			this->chart3->TabIndex = 13;
			this->chart3->Text = L"chart3";
			title3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			title3->Name = L"Title1";
			title3->Text = L"<X^2>";
			this->chart3->Titles->Add(title3);
			this->chart3->Click += gcnew System::EventHandler(this, &MyForm::chart3_Click);
			// 
			// chart4
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea4);
			this->chart4->Location = System::Drawing::Point(1373, 105);
			this->chart4->Name = L"chart4";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Name = L"Series1";
			this->chart4->Series->Add(series5);
			this->chart4->Size = System::Drawing::Size(286, 448);
			this->chart4->TabIndex = 14;
			this->chart4->Text = L"chart4";
			title4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			title4->Name = L"Title1";
			title4->Text = L"Зависимость координаты частицы от времени";
			this->chart4->Titles->Add(title4);
			this->chart4->Click += gcnew System::EventHandler(this, &MyForm::chart4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1102, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(247, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Все графики относятся к одномерному случаю";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(1523, 45);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1370, 48);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(147, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Фрактальная размерность";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1695, 593);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->chart4);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		N = Convert::ToInt64(textBox1->Text);
		this->chart2->Series[0]->Points->Clear();
		this->chart3->Series[0]->Points->Clear();
		this->chart4->Series[0]->Points->Clear();
		del = Convert::ToInt64(textBox2->Text);
	
	
		
		w_ = this->panel1->Width;
		h_ = this->panel1->Height;

		mol = new particle(N,r,del);
		

		mol->V = V_;
		mol->h = h_;
		mol->w = w_;
        

		mol->Nach_polon();
		mol->massiveXY();

		image = panel1->CreateGraphics();
		
		this->bufferedGraphicsContext = BufferedGraphicsManager::Current;
		this->bufferedGraphicsContext->MaximumBuffer = System::Drawing::Size(w_, h_ );
		this->bufferedGraphics = bufferedGraphicsContext->Allocate(image, Rectangle(0, 0, w_ , h_ ));
		this->bufferedGraphics->Graphics->Clear(panel1->BackColor);


		w_2 = this->panel2->Width;
		h_2 = this->panel2->Height;

		mol2 = new particle(N, r,del);

		mol2->V = V_;
		mol2->h = h_2;
		mol2->w = w_2;
        

		mol2->Nach_polon2D();


		image2 = panel2->CreateGraphics();

		this->bufferedGraphicsContext2 = BufferedGraphicsManager::Current;
		this->bufferedGraphicsContext2->MaximumBuffer = System::Drawing::Size(w_2, h_2);
		this->bufferedGraphics2 = bufferedGraphicsContext2->Allocate(image2, Rectangle(0, 0, w_2, h_2));
		this->bufferedGraphics2->Graphics->Clear(panel2->BackColor);


		timer1->Enabled = true;

		
	}
		   void Draw()
		   {
			   Brush^ brush;
			   int xx, yy;
			   for (int i = 0;i < N;i++)
			   {
				   xx = mol->p[i].x;
				   yy = mol->p[i].y;
				   brush = gcnew SolidBrush(Color::Red);
				   bufferedGraphics->Graphics->FillEllipse(brush, xx*1., yy*1.,r,r);
			   }
			   bufferedGraphics->Render();
		   }
		   void Draw2()
		   {
			   Brush^ brush2;
			   int xx, yy;
			   for (int i = 0;i < N;i++)
			   {
				   xx = mol2->p[i].x;
				   yy = mol2->p[i].y;
				    brush2 = gcnew SolidBrush(Color::Red);
				   bufferedGraphics2->Graphics->FillEllipse(brush2, xx * 1., yy * 1., r, r);
			   }
			   bufferedGraphics2->Render();
		   }
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	


	bufferedGraphics->Graphics->Clear(Color::White);
	bufferedGraphics2->Graphics->Clear(Color::White);
	N = Convert::ToInt64(textBox1->Text);
	del = Convert::ToInt64(textBox2->Text);

		mol->Move();
		mol->massiveXY();
		//////////////////////////////////Код графика//////////////////////////////////////////////////
		this->chart1->Series[0]->Points->Clear();
		
		double* Y = mol->Yy;
		//double* X = mol->X;//слишком мал или слишком больш//решил проблему через массив float, а не double
		float* X = new float[del];
		
      
		for (int i = 0;i < del;i++)
		{
			X[i] = (w_ * 1.) / (del * 1.) * (i+1);
			this->chart1->Series[0]->Points->AddXY(X[i], Y[i]);
		
		fin << X[i] << "   " << Y[i] << endl;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////
		Draw();

		mol2->Move2D();
		Draw2();
	
		double* sum = new double[N];
		double Sum = 0;
		sum = mol->Xx;
        #pragma omp parallel for reduction(+:Sum)
		for (int i = 0;i < N;i++)
		{
			Sum += (sum[i]-w_/2.);
		}
		Sum = Sum / N;
		this->chart2->Series[0]->Points->AddXY(One_Tick, Sum);

		
		double Sum2 = 0;
     #pragma omp parallel for reduction(+:Sum2)
		for (int i = 0;i < N;i++)
		{
			if (sum[i] >= w_ / 2.) 
			{
				Sum2 += (sum[i]-w_/2.) * (sum[i]-w_/2.);
			}
			else
			{
				Sum2 += ((w_ - sum[i])-w_/2) * ((w_ - sum[i])-w_/2);
			}

		}
		Sum2 = Sum2 / N;
		this->chart3->Series[0]->Points->AddXY(One_Tick, Sum2);


		this->chart4->Series[0]->Points->AddXY(One_Tick,sum[0]-w_/2.);
	
		
		One_Tick += 1;
	fract[One_Tick] = sum[0] - w_ / 2.;
	
	//fin2 << One_Tick << "   " << Sum2 << endl;

}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	textBox4->Text = "" +(2.- HCALC(fract, One_Tick));
	fin.close();
	//fin2.close();
}



private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}





private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[1]->Points->Clear();
	w_ = this->panel1->Width;
	
	//double* X = mol->X;//слишком мал или слишком больш//решил проблему через массив float, а не double
	float x;
	double xi = w_ / 2.;
	double sigma = 100;
	double umnojka=Convert::ToDouble(textBox3->Text);


	for (int i = 1;i <w_;i++)
	{

		x=i;
		this->chart1->Series[1]->Points->AddXY(x,umnojka*(1./sqrt(sigma*3.14)*exp(-(x-xi-100)*(x-xi-100)/2./sigma/sigma)));
	}
}
private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void chart3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->chart4->Series[0]->Points->Clear();
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
