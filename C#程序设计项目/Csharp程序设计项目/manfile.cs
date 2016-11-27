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
    public partial class manfile : Form
    {
        public bool quanxian = false;
        public people peo = new people();
        public const string filename = "info.txt";
        public List<people> peoList = Main.PeoList;
        public manfile()
        {
            InitializeComponent();
            //people p = peoList[0];
            //MessageBox.Show(p.name);
            
        }

        public manfile(string bumen,bool quanxian)
        {
            InitializeComponent();
            comboBox1.Text = bumen;
            this.quanxian = quanxian;
        }

        public manfile(bool quanxian)
        {
            InitializeComponent();
            this.quanxian = quanxian;
        }
        public manfile(people p,bool quanxian)
        {
            InitializeComponent();
            this.quanxian = quanxian;
            this.peo = p;
            comboBox1.Text = p.bumen;
            textBox1.Text = p.id;
            textBox2.Text = p.name;
            comboBox6.Text = p.bumen;
            comboBox2.Text = p.minzu;
            comboBox3.Text = p.whcd;
            textBox3.Text = p.sfz;
            comboBox4.Text = p.hy;
            comboBox5.Text = p.sex;
            dateTimePicker1.Value = p.birthday;
            textBox4.Text = p.nl.ToString();
            textBox5.Text = p.phonum;
            textBox6.Text = p.QQ;
            textBox7.Text = p.email;
            textBox8.Text = p.wechat;
            textBox9.Text = p.address;
            if (peo.picture == null)
            {
                pictureBox1.Image = null;
            }
            else
            {
                pictureBox1.Image = Image.FromFile(p.picture);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex >= 1)
                comboBox1.SelectedIndex--;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex >= 1)
                listBox1.SelectedIndex--;
            else if(listBox1.SelectedIndex==-1)
            {
                listBox1.SelectedIndex = listBox1.Items.Count - 1;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex < listBox1.Items.Count - 1)
                listBox1.SelectedIndex++;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex < comboBox1.Items.Count - 1)
                comboBox1.SelectedIndex++;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBox1.Items.Count!=0)
            {
                listBox1.Items.Clear();
            }
            
            foreach (people p in peoList)
            {
                if (p.bumen == comboBox1.Text)
                {
                    listBox1.Items.Add(p.name);
                }
            }
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox6.Text = "";
            comboBox2.Text = "";
            comboBox3.Text = "";
            textBox3.Text = "";
            comboBox4.Text = "";
            comboBox5.Text = "";
            dateTimePicker1.Value = DateTime.Now;
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            pictureBox1.Image = null;

        }

        private void button9_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex >= 0)
            {
                string name = listBox1.SelectedItem.ToString();
                peo = peoList.Find((x) => { return x.name == name; });
                //MessageBox.Show(p.name);
                textBox1.Text = peo.id;
                textBox2.Text = peo.name;
                comboBox6.Text = peo.bumen;
                comboBox2.Text = peo.minzu;
                comboBox3.Text = peo.whcd;
                textBox3.Text = peo.sfz;
                comboBox4.Text = peo.hy;
                comboBox5.Text = peo.sex;
                dateTimePicker1.Value = peo.birthday;
                textBox4.Text = peo.nl.ToString();
                textBox5.Text = peo.phonum;
                textBox6.Text = peo.QQ;
                textBox7.Text = peo.email;
                textBox8.Text = peo.wechat;
                textBox9.Text = peo.address;
                if (peo.picture == null)
                {
                    pictureBox1.Image = null;
                }
                else
                {
                    pictureBox1.Image = Image.FromFile(peo.picture);
                }
            }
            
        }

        private void button8_Click(object sender, EventArgs e)
        {
            //string fname=null;
            openFileDialog1.InitialDirectory = Application.StartupPath;
            peo = peoList.Find((x) => { return x.name == textBox2.Text; });
            if(peo==null)
            {
                peo = new people();
            }
            else if (peo.name != textBox2.Text)
            {
                peo = new people();
            }
            openFileDialog1.Filter = "图片文件|*.jpg;*.png;*.gif;*.jpeg";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                peo.picture = openFileDialog1.SafeFileName;
                pictureBox1.Image = Image.FromFile(peo.picture);
            }
        }

        private void button9_Click_1(object sender, EventArgs e)
        {
            if(peo.name != textBox2.Text)
            {
                peo=new people();
            }
            peo.picture = null;
            pictureBox1.Image = null;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if(peo.name!=null)
            {
                peo = new people();
            }
            peo.id = textBox1.Text;
            peo.name = textBox2.Text;
            peo.bumen = comboBox6.Text;
            peo.minzu = comboBox2.Text;
            peo.whcd = comboBox3.Text;
            peo.sfz = textBox3.Text;
            peo.hy = comboBox4.Text;
            peo.sex = comboBox5.Text;
            peo.birthday = dateTimePicker1.Value;
            peo.nl=Int32.Parse(textBox4.Text);
            peo.phonum = textBox5.Text;
            peo.QQ = textBox6.Text;
            peo.email = textBox7.Text;
            peo.wechat = textBox8.Text;
            peo.address = textBox9.Text;
            if (peo.bumen == comboBox1.Text)
            {
                listBox1.Items.Add(peo.name);
            }
            
            //if(pictureBox1.Image==null)
            //{

            //}
            //peo.picture = pictureBox1.ImageLocation;
            peoList.Add(peo);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            people p = peoList.Find((x) => { return x.name == peo.name; });
            p.id = textBox1.Text;
            p.name = textBox2.Text;
            p.bumen = comboBox6.Text;
            p.minzu = comboBox2.Text;
            p.whcd = comboBox3.Text;
            p.sfz = textBox3.Text;
            p.hy = comboBox4.Text;
            p.sex = comboBox5.Text;
            p.birthday = dateTimePicker1.Value;
            p.nl = Int32.Parse(textBox4.Text);
            p.phonum = textBox5.Text;
            p.QQ = textBox6.Text;
            p.email = textBox7.Text;
            p.wechat = textBox8.Text;
            p.address = textBox9.Text;
            p.picture = peo.picture;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            people p = peoList.Find((x) => { return x.name == peo.name; });
            peoList.Remove(p);
            if (listBox1.SelectedIndex != -1)
                listBox1.Items.RemoveAt(listBox1.SelectedIndex);
            listBox1.SelectedIndex = -1;
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox6.Text = "";
            comboBox2.Text = "";
            comboBox3.Text = "";
            textBox3.Text = "";
            comboBox4.Text = "";
            comboBox5.Text = "";
            dateTimePicker1.Value = DateTime.Now;
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            pictureBox1.Image = null;
        }

        private void manfile_Load(object sender, EventArgs e)
        {
            if(quanxian)
            {
                button5.Enabled = button6.Enabled = button7.Enabled = button8.Enabled = button9.Enabled = true;
            }
            else
            {
                button5.Enabled = button6.Enabled = button7.Enabled = button8.Enabled = button9.Enabled = false;
            }
        }
    }
}
