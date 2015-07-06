#pragma once

namespace TypingNoviceLive {

	//using namespace System;
	//using namespace System::ComponentModel;
	//using namespace System::Collections;
	//using namespace System::Windows::Forms;
	//using namespace System::Data;
	//using namespace System::Drawing;

	//System::Boolean Checked;
	//System::Media::SoundPlayer mus;
	//System::Media::SoundPlayer^ mus;

	/*System::Void play_music()
	{
		while (1)
		{
			if (Checked)
				mus->PlayLooping();
			else
				mus->Stop();

			System::Threading::Thread::Sleep(100);
		}
	}*/

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->status = 0;
			this->init_loc = gcnew System::Random();

			this->hitted = 0;
			this->missed = 0;
			this->total = 0;
			//this->label_hit->Text = this->hitted.ToString();
			//this->label_miss->Text = this->missed.ToString();
			//This will cause CheckChanged and then NullReference exception
			//this->check_music->Checked = true;

			/*this->mus = gcnew System::Media::SoundPlayer();
			this->mus->SoundLocation = "7.wav";
			this->mus->Load();*/

			this->check_music->Checked = true;

			//No good, Alt + F4 will terminate
			//this->ControlBox = false;

			//this->panel_game->BackColor = System::Drawing::Color::Black;
			//this->BackColor = System::Drawing::Color::Gray;
			this->panel_game->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->BackColor = System::Drawing::Color::FromArgb(0xff, 100, 100, 100);
			this->button_trigger->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->button_quit->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->check_music->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->numericUpDown_level->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->numericUpDown_missable->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->text_typed->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
			this->text_typed->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);
			this->button_quit->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);
			this->button_trigger->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);
			this->text_typed->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);
			this->check_music->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);;
			this->numericUpDown_level->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);;
			this->numericUpDown_missable->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);

			//This call is to classify the words according to their length
			//And should not always be here
			//this->select_word();

			//this->init_word();

			//System::Threading::Thread^ back_music = gcnew System::Threading::Thread(play_music);
			//back_music->Start();
		}

	protected:
		/// <summary>
		/// Clean up any remissables being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	//Nothing seen?
	/*protected: virtual void WndProc(System::Windows::Forms::Message% m) override
	{
		if (m.Msg == 0x84 && (int)m.Result == 0x1)
		{
			//System::Windows::Forms::Form::WndProc(m);
			m.Result == (System::IntPtr)0x2;
		}

		System::Windows::Forms::Form::WndProc(m);
	}*/

	private: System::Windows::Forms::CheckBox^  check_music;




	private: System::Windows::Forms::TextBox^  text_typed;
	private: System::Windows::Forms::Button^  button_trigger;
	private: System::Windows::Forms::Timer^  timer_speed;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  button_quit;

	//whether the game is on or not
	//0 ready to start, 1 is on, 2 is pause and 3 is ended
	private: System::Int16 status;

	private: System::Random^ init_loc;

	private: System::Int16 hitted;
	private: System::Int16 missed;
	private: System::Int16 total;
	private: const System::Int16 source = 250;
	private: array<System::String^>^ suitable;
	private: System::Int16 missable;
	private: const System::Int16 word_num = 5;
	private: const System::Int16 word_interval = 100;
	private: const System::Int16 fastest = 100;
	private: const System::Int16 lowest = 1000;
	//private: System::Media::SoundPlayer^ mus;

	private: array<System::Windows::Forms::Label^>^ words;




	private: System::Windows::Forms::NumericUpDown^  numericUpDown_level;
	private: System::Windows::Forms::Label^  label_static_level;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_missable;








	private: System::Windows::Forms::Panel^  panel_game;	

	/*private: System::Void select_word()
	{
		System::IO::StreamReader^ dict = gcnew System::IO::StreamReader("dict.txt");
		System::IO::StreamWriter^ suitable = gcnew System::IO::StreamWriter("level7.txt");
		while (dict->Peek() >= 0)
		{
			System::String^ line = dict->ReadLine();
			//System::Windows::Forms::MessageBox::Show(line);

			array<wchar_t>^ sep = { ' ' };
			array<System::String^>^ word = line->Split(sep);
			//System::Windows::Forms::MessageBox::Show(word[0]);

			if (word[0]->Length == 10)
			{
				//System::Windows::Forms::MessageBox::Show(word[0]);
				suitable->WriteLine(word[0]);
			}

		}
		dict->Close();
		suitable->Close();
	}*/
	private: System::Void init_word(System::Int16 level)
	{
		this->suitable = gcnew array<System::String^>(this->source);
		System::IO::StreamReader^ dict = gcnew System::IO::StreamReader("level" + level.ToString() + ".txt");
		for (System::Int16 i = 0; i < this->source; i++)
		{
			this->suitable[i] = gcnew System::String(dict->ReadLine());
		}
		dict->Close();
		//No meaning?
		//::Windows::Forms::MessageBox::Show(this->suitable->ToString());
	}
	private: System::Void shuffle_word()
	{
		System::Random^ r = gcnew System::Random();
		for (System::Int16 i = 0; i < this->source; i++)
		{
			System::Int16 t = r->Next(this->source);
			System::String^ m = this->suitable[i];
			this->suitable[i] = this->suitable[t];
			this->suitable[t] = m;
		}
	}
	/*public: System::Void play_music()
	{
		while (1)
		{
			if (this->check_music->Checked)
				this->mus->PlayLooping();
			else
				this->mus->Stop();

			System::Threading::Thread::Sleep(100);
		}
	}*/
	private: System::Void start_game()
	{
		this->timer_speed->Interval = this->lowest;
		this->timer_speed->Enabled = true;

		this->shuffle_word();

		//Look look
		//System::Drawing::Rectangle game_rect = this->panel_game->ClientRectangle;
		//System::Windows::Forms::MessageBox::Show(game_rect.ToString());

		this->words = gcnew array<System::Windows::Forms::Label^>(10);

		//System::Random^ init_loc = gcnew System::Random();

		System::Int16 i;
		for (i = 0; i < word_num; i++)
		{
			this->words[i] = gcnew System::Windows::Forms::Label();

			this->words[i]->AutoSize = true;
			this->words[i]->BackColor = System::Drawing::Color::Transparent;
			this->words[i]->ForeColor = System::Drawing::Color::FromArgb(0xff, 150, 150, 150);
			this->words[i]->Font =  gcnew System::Drawing::Font("Times New Roman", 12, System::Drawing::FontStyle::Bold);
			//this->words[i]->Text = "LABEL" + i.ToString();
			this->words[i]->Text = this->suitable[this->total];
			this->total++;

			this->words[i]->Location = System::Drawing::Point(this->init_loc->Next(this->panel_game->ClientRectangle.Width - this->words[i]->Width), i * -word_interval);
			
			if (this->panel_game->ClientRectangle.Width - this->words[i]->Location.X <= this->words[i]->Width)
				this->words[i]->Location.X -= this->words[i]->Width * 2;

			this->words[i]->Name = i.ToString();
			this->words[i]->Size = System::Drawing::Size(30, 12);
			this->words[i]->TabIndex = i;

			//Matters?
			//this->SuspendLayout();

			/*this->timer_speed->Enabled = false;
			System::Windows::Forms::MessageBox::Show(i.ToString()
				+ "\n" + this->words[i]->Location.ToString()
				+ "\n" + this->panel_game->ClientRectangle.ToString()
				+ "\n" + this->words[i]->Width.ToString());
			this->timer_speed->Enabled = true;*/

			this->panel_game->Controls->Add(this->words[i]);
			//System::Threading::Thread::Sleep(1000);

			
			//Just a shot
			//System::Windows::Forms::MessageBox::Show(i.ToString ());
		}
	}
	private: System::Void update_words()
	{
		//Memberization
		//System::Random^ init_loc = gcnew System::Random();

		for (System::Int16 i = 0; i < word_num; i++)
		{
			System::Int16 y = this->words[i]->Location.Y + 20;
			if (y >= this->panel_game->ClientRectangle.Height)
			{
				this->missed++;
				
				//this->label_miss->Text = this->missed.ToString();

				if (this->missed == this->missable)
				{
					//Terminate and show statistics
					this->timer_speed->Enabled = false;
					this->status = 0;
					this->numericUpDown_level->Enabled = true;
					this->numericUpDown_missable->Enabled = true;

					this->button_trigger->Text = "Start";

					System::Windows::Forms::DialogResult ret = System::Windows::Forms::MessageBox::Show("You shot "
						+ this->hitted.ToString()
						+ " words\nAnd you missed "
						+ this->missed.ToString()
						+ " words\nSo your success rate is "
						+ (this->hitted * 100 / (this->hitted + this->missed)).ToString() + "%\nRetry?",
						"Game over:",
						System::Windows::Forms::MessageBoxButtons::RetryCancel, System::Windows::Forms::MessageBoxIcon::Information);

					for (System::Int16 i = 0; i < this->word_num; i++)
						this->panel_game->Controls->Remove(this->words[i]);

					this->hitted = 0;
					this->missed = 0;
					this->total = 0;
					//this->label_hit->Text = this->hitted.ToString();
					//this->label_miss->Text = this->missed.ToString();

					if (ret == System::Windows::Forms::DialogResult::Cancel)
						return;
					else if (ret == System::Windows::Forms::DialogResult::Retry)
					{
						this->start_game();
						this->button_trigger->Text = "Pause";
						this->status = 1;
					}
				}
				this->numericUpDown_missable->Value = this->missable - this->missed;

				y = 0;
				//this->words[i]->Text = "LABEL" + i.ToString();
				this->words[i]->Text = this->suitable[this->total];
				this->total++;
				this->words[i]->Location = System::Drawing::Point(this->init_loc->Next(this->panel_game->ClientRectangle.Width - this->words[i]->Width), i * -word_interval);


				/*if (this->panel_game->ClientRectangle.Width - this->words[i]->Location.X <= this->words[i]->Width)
				{
					this->timer_speed->Enabled = false;

					System::Windows::Forms::MessageBox::Show(this->words[i]->Location.ToString());

					this->words[i]->Location.X -= this->words[i]->Width * 2;

					System::Windows::Forms::MessageBox::Show(i.ToString()
						+ "\n" + this->words[i]->Location.ToString()
						+ "\n" + this->panel_game->ClientRectangle.ToString()
						+ "\n" + this->words[i]->Width.ToString());

					this->timer_speed->Enabled = true;
				}*/

			}
			this->words[i]->Location = System::Drawing::Point(this->words[i]->Location.X, y);
			
			//Oh shit!!!
			//i++;
		}

	}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->check_music = (gcnew System::Windows::Forms::CheckBox());
			this->text_typed = (gcnew System::Windows::Forms::TextBox());
			this->button_trigger = (gcnew System::Windows::Forms::Button());
			this->timer_speed = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_quit = (gcnew System::Windows::Forms::Button());
			this->panel_game = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown_level = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_static_level = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_missable = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_level))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_missable))->BeginInit();
			this->SuspendLayout();
			// 
			// check_music
			// 
			this->check_music->AutoSize = true;
			this->check_music->Location = System::Drawing::Point(3, 515);
			this->check_music->Name = L"check_music";
			this->check_music->Size = System::Drawing::Size(54, 17);
			this->check_music->TabIndex = 0;
			this->check_music->Text = L"Music";
			this->check_music->UseVisualStyleBackColor = true;
			// 
			// text_typed
			// 
			this->text_typed->Location = System::Drawing::Point(54, 513);
			this->text_typed->Name = L"text_typed";
			this->text_typed->Size = System::Drawing::Size(100, 20);
			this->text_typed->TabIndex = 5;
			this->text_typed->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::text_typed_KeyPress);
			// 
			// button_trigger
			// 
			this->button_trigger->Location = System::Drawing::Point(157, 512);
			this->button_trigger->Margin = System::Windows::Forms::Padding(0);
			this->button_trigger->Name = L"button_trigger";
			this->button_trigger->Size = System::Drawing::Size(62, 23);
			this->button_trigger->TabIndex = 6;
			this->button_trigger->Text = L"Start";
			this->button_trigger->UseVisualStyleBackColor = true;
			this->button_trigger->Click += gcnew System::EventHandler(this, &MyForm::button_trigger_Click);
			// 
			// timer_speed
			// 
			this->timer_speed->Tick += gcnew System::EventHandler(this, &MyForm::timer_speed_Tick);
			// 
			// button_quit
			// 
			this->button_quit->Location = System::Drawing::Point(225, 511);
			this->button_quit->Margin = System::Windows::Forms::Padding(0);
			this->button_quit->Name = L"button_quit";
			this->button_quit->Size = System::Drawing::Size(57, 23);
			this->button_quit->TabIndex = 7;
			this->button_quit->Text = L"Quit";
			this->button_quit->UseVisualStyleBackColor = true;
			this->button_quit->Click += gcnew System::EventHandler(this, &MyForm::button_quit_Click);
			this->button_quit->MouseLeave += gcnew System::EventHandler(this, &MyForm::button_quit_MouseLeave);
			this->button_quit->MouseHover += gcnew System::EventHandler(this, &MyForm::button_quit_MouseHover);
			// 
			// panel_game
			// 
			this->panel_game->Location = System::Drawing::Point(3, 2);
			this->panel_game->Name = L"panel_game";
			this->panel_game->Size = System::Drawing::Size(392, 501);
			this->panel_game->TabIndex = 8;
			this->panel_game->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_game_MouseDown);
			this->panel_game->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_game_MouseMove);
			// 
			// numericUpDown_level
			// 
			this->numericUpDown_level->Location = System::Drawing::Point(311, 513);
			this->numericUpDown_level->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDown_level->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_level->Name = L"numericUpDown_level";
			this->numericUpDown_level->Size = System::Drawing::Size(28, 20);
			this->numericUpDown_level->TabIndex = 11;
			this->numericUpDown_level->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_level->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_level_ValueChanged);
			// 
			// label_static_level
			// 
			this->label_static_level->AutoSize = true;
			this->label_static_level->Location = System::Drawing::Point(289, 517);
			this->label_static_level->Name = L"label_static_level";
			this->label_static_level->Size = System::Drawing::Size(23, 13);
			this->label_static_level->TabIndex = 12;
			this->label_static_level->Text = L"LV.";
			// 
			// numericUpDown_missable
			// 
			this->numericUpDown_missable->Location = System::Drawing::Point(352, 514);
			this->numericUpDown_missable->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown_missable->Name = L"numericUpDown_missable";
			this->numericUpDown_missable->Size = System::Drawing::Size(43, 20);
			this->numericUpDown_missable->TabIndex = 13;
			this->numericUpDown_missable->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 544);
			this->Controls->Add(this->numericUpDown_missable);
			this->Controls->Add(this->label_static_level);
			this->Controls->Add(this->numericUpDown_level);
			this->Controls->Add(this->panel_game);
			this->Controls->Add(this->button_quit);
			this->Controls->Add(this->button_trigger);
			this->Controls->Add(this->text_typed);
			this->Controls->Add(this->check_music);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"TypeTypeType!!!";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_level))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_missable))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//private: System::Void check_music_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		//This will cause appcrash!Endless loop!
		/*if (this->check_music->Checked)
			this->check_music->Checked = false;
		else
			this->check_music->Checked = true;*/

		//Just a shot because I am unfamiliar with dotnet
		/*if (this->check_music->Checked)
			System::Windows::Forms::MessageBox::Show("Checked!");
		else
			System::Windows::Forms::MessageBox::Show("Unchecked!");*/

		/*if (this->check_music->Checked)
			mus->PlayLooping();
		else
			mus->Stop();*/
	//}
	private: System::Void text_typed_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == '\r')
		{
			//Just a shot
			//System::Windows::Forms::MessageBox::Show("Entered!");

			if (this->text_typed->Text != "")
			{
				//Just a shot
				//System::Windows::Forms::MessageBox::Show("Entered " + this->text_typed->Text);

				for (System::Int16 i = 0; i < word_num; i++)
				{
					if (this->text_typed->Text->ToLower () == this->words[i]->Text->ToLower ())
					{
						this->hitted++;

						if (this->timer_speed->Interval >= this->fastest + 25)
							this->timer_speed->Interval -=  25;

						//Just like debugging
						//System::Windows::Forms::MessageBox::Show(this->timer_speed->Interval.ToString());

						//this->label_hit->Text = this->hitted.ToString();

						//this->words[i]->Text = "LABEL" + i.ToString();
						this->words[i]->Text = this->suitable[this->total];
						this->total++;

						if (this->check_music->Checked)
						{
							System::Media::SoundPlayer^ hit = gcnew System::Media::SoundPlayer();
							hit->SoundLocation = "hit.wav";
							hit->Load();
							hit->Play();
							//hit->Stop();

							//this->mus->PlayLooping();

							//System::Media::SystemSounds::Asterisk->Play();

							//No
							//this->mus->PlayLooping();
						}

						this->words[i]->Location = System::Drawing::Point(this->init_loc->Next(this->panel_game->ClientRectangle.Width - this->words[i]->Width), i * -word_interval);
						
						/*if (this->panel_game->ClientRectangle.Width - this->words[i]->Location.X <= this->words[i]->Width)
						{
							this->timer_speed->Enabled = false;

							System::Windows::Forms::MessageBox::Show(this->words[i]->Location.ToString());

							this->words[i]->Location.X -= this->words[i]->Width * 2;

							System::Windows::Forms::MessageBox::Show(i.ToString()
								+ "\n" + this->words[i]->Location.ToString()
								+ "\n" + this->panel_game->ClientRectangle.ToString()
								+ "\n" + this->words[i]->Width.ToString());

							this->timer_speed->Enabled = true;
						}*/
					}
				}
				this->text_typed->Text = "";
			}
		}
	}
	private: System::Void button_trigger_Click(System::Object^  sender, System::EventArgs^  e) {
		//Just a shot
		//System::Windows::Forms::MessageBox::Show("Clicked!");

		if (status == 0)
		{
			this->missable = System::Decimal::ToInt16(this->numericUpDown_missable->Value);

			//Start the game
			this->init_word(System::Decimal::ToInt16(this->numericUpDown_level->Value));
			//System::Windows::Forms::MessageBox::Show(this->numericUpDown_level->Value.ToString());

			//System::Windows::Forms::MessageBox::Show(this->textBox_missable->Text);
			//this->missable = System::Convert::ToInt16(this->textBox_missable->Text);

			//if (this->missable <= 0)
				//this->missable = 10;

			//init_word needs missable
			//this->missable = System::Decimal::ToInt16(this->numericUpDown_missable->Value);

			this->numericUpDown_level->Enabled = false;
			//this->textBox_missable->Enabled = false;
			this->numericUpDown_missable->Enabled = false;

			this->button_trigger->Text = "Pause";
			this->status = 1;

			this->start_game();
		}
		else if (status == 1)
		{
			//Pause the game
			this->button_trigger->Text = "Start";
			this->status = 2;
			this->timer_speed->Enabled = false;
		}
		else if (status == 2)
		{
			this->button_trigger->Text = "Pause";
			this->status = 1;
			this->timer_speed->Enabled = true;
		}
	}
	//I wonder how i can merge these two functions
	//Good! System::Windows::Forms::Application::Exit() will raise the event
	private: System::Void button_quit_Click(System::Object^  sender, System::EventArgs^  e) {
		//It could not be!
		//this->MyForm_FormClosing();

		//Suspend the game first
		//TODO
		//

		/*System::Windows::Forms::DialogResult ret = System::Windows::Forms::MessageBox::Show(
			"Are you sure to quit the game?", "Please confirm:",
			System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question);

		if (ret == System::Windows::Forms::DialogResult::Yes)*/
		//{
			//Quit the game

			//Just a shot
			//System::Windows::Forms::MessageBox::Show("Quit!");
			
			System::Windows::Forms::Application::Exit();
		//}
		//else if (ret == System::Windows::Forms::DialogResult::No)
		//{
		//	//Resume the game

		//	//Just a shot
		//	//System::Windows::Forms::MessageBox::Show("Resume!");
		//}
	}
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//Suspend the game first
		//TODO
		//
		this->timer_speed->Enabled = false;
		this->button_trigger->Text = "Start";
		this->status = 2;

		System::Windows::Forms::DialogResult ret = System::Windows::Forms::MessageBox::Show(
			"Are you sure to quit the game?", "Please confirm:",
			System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question);

		if (ret == System::Windows::Forms::DialogResult::Yes)
		{
			//Quit the game

			//Just a shot
			//System::Windows::Forms::MessageBox::Show("Quit!");
		}
		else if (ret == System::Windows::Forms::DialogResult::No)
		{
			//Resume the game

			//Just a shot
			//System::Windows::Forms::MessageBox::Show("Resume!");

			e->Cancel = true;
			
			//Don't do this
			//this->timer_speed->Enabled = true;
		}
	}
	private: System::Void timer_speed_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->update_words();
	}

	//Not so satisfying
	private: System::Drawing::Point^ p;
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			p = System::Drawing::Point(e->X, e->Y);
		}
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
			this->Location = System::Drawing::Point(this->Location.X + e->X - p->X, this->Location.Y + e->Y - p->Y);
	}
	private: System::Void panel_game_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			p = System::Drawing::Point(e->X, e->Y);
		}
	}
	private: System::Void panel_game_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
			this->Location = System::Drawing::Point(this->Location.X + e->X - p->X, this->Location.Y + e->Y - p->Y);
	}
	private: System::Void numericUpDown_level_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button_quit_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->button_quit->BackColor = System::Drawing::Color::FromArgb(0xff, 0xff, 50, 50);
	}
	private: System::Void button_quit_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->button_quit->BackColor = System::Drawing::Color::FromArgb(0xff, 50, 50, 50);
	}
};
}
