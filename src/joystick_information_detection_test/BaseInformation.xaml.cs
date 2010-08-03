using System.Windows;

namespace Joystick_2008_To_WPF
{
    /// <summary>
    /// Interaction logic for BaseInformation.xaml
    /// </summary>
    public partial class BaseInformation
    {
        public BaseInformation(string inf)
        {
            InitializeComponent();
            string[] s = inf.Split('#');
            for (int i = 0; i < s.Length; i++)
            {
                textBox1.Text += s[i];
            }
        }
    }
}
