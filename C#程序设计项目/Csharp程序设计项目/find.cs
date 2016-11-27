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
    public partial class find : Form
    {
        public List<people> peoList = Main.PeoList;
        List<people> cppeoList = new List<people>(Main.PeoList);
        public find()
        {
            InitializeComponent();
        }

        private void find_Load(object sender, EventArgs e)
        {
            //cppeoList = new List<people>(Main.PeoList);
            //foreach (people p in cppeoList)
            //{
            //    if (p.bumen != comboBox1.Text)
            //        p.biaoji = true;
            //}
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            cppeoList = new List<people>(Main.PeoList);
            foreach (people p in cppeoList)
            {
                p.biaoji = true;
            }
            if (comboBox1.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.bumen != comboBox1.Text)
                        p.biaoji = false;
                }
            }
            if (comboBox2.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.whcd != comboBox2.Text)
                        p.biaoji = false;
                }
            }
            if (comboBox3.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.minzu != comboBox3.Text)
                        p.biaoji = false;
                }
            }
            if (comboBox4.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.sex != comboBox4.Text)
                        p.biaoji = false;
                }
            }
            if (comboBox5.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.hy != comboBox5.Text)
                        p.biaoji = false;
                }
            }
            if (textBox1.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.id != textBox1.Text)
                        p.biaoji = false;
                }
            }
            if (textBox2.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.name != textBox2.Text)
                        p.biaoji = false;
                }
            }
            if (textBox3.Text != "")
            {
                foreach (people p in cppeoList)
                {
                    if (p.sfz != textBox3.Text)
                        p.biaoji = false;
                }
            }
            if(cppeoList.Count>=1)
            {
                foreach (people p in cppeoList)
                {
                    if (p.biaoji)
                    {
                        string item = "姓名：" + p.name + "  编号：" + p.id + "  部门：" + p.bumen + "  手机：" + p.phonum;
                        listBox1.Items.Add(item);
                    }
                    
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            comboBox1.Text = "";
            comboBox2.Text = "";
            comboBox3.Text = "";
            comboBox4.Text = "";
            comboBox5.Text = "";
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            listBox1.Items.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {

            int num = -1;
            for (int i = 0; i < peoList.Count; i++)
            {
                if (peoList[i].biaoji == true)
                    num++;
                if (num == listBox1.SelectedIndex)
                {
                    people p = peoList[i];
                    //MessageBox.Show(p.name);
                    manfile mf = new manfile(p, Main.quanxian);
                    mf.Show();
                    break;
                }
            }
            //MessageBox.Show("doubleclick");
        }

        private void listBox1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            //MessageBox.Show("mousedoubleclick");
        }
    }
}
