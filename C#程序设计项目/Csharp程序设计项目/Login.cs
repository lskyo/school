using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Csharp程序设计项目
{
    public partial class Login : Form
    {
        int num = 0;
        public Login()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "" || textBox2.Text == "")
            {
                MessageBox.Show("请输入帐号或密码。");
                textBox1.Text = "";
                textBox2.Text = "";
                num++;
                if(num>=3)
                {
                    MessageBox.Show("输入错误超过三次，程序退出。");
                    Application.Exit();
                }
            }
            else
            {
                if (textBox1.Text == "admin" && textBox2.Text == "admin" || textBox1.Text == "visiter" && textBox2.Text == "admin")
                {
                    num = 0;
                    this.Hide();
                    Main f;
                    if (textBox1.Text == "visiter")
                        f = new Main(false,this);
                    else
                        f = new Main(true,this);
                    //this.Close();
                    f.Show();
                    textBox1.Text = "";
                    textBox2.Text = "";
                    //textBox1.Focus();
                    //this.Show();

                }
                else
                {
                    MessageBox.Show("帐号或密码错误。");
                    textBox1.Text = "";
                    textBox2.Text = "";
                    //textBox1.Focus();
                    num++;
                    if (num >= 3)
                    {
                        MessageBox.Show("输入错误超过三次，程序退出。");
                        Application.Exit();
                    }
                }
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
