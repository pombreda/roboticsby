using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;
using System.Windows;
using System.IO;
using Joystick_2008_To_WPF.PInvoke;

namespace Joystick_2008_To_WPF.WorkWithDataBase
{
    class GetDatasFromXmlFile
    {
        /// <summary>
        /// return corporation name and joystick name
        /// </summary>
        /// <param name="joyNum"></param>
        /// <param name="devices"></param>
        /// <returns></returns>
        public static string GetNames(int joyNum, List<FindAllJoys.FindingDevice> devices)
        {
            if (devices.Count > 0)
            {
                try
                {
                    string joyName = "", corpName = "";
                    string hexVendor = String.Format("{0:x}", devices[joyNum].Attr.VendorId);
                    string hexProduct = String.Format("{0:x}", devices[joyNum].Attr.ProductId);
                    var fi = new FileInfo("VendorsAndProductsBase.xml");
                    if (fi.Length > 0)
                    {
                        var xDocument = XDocument.Load("VendorsAndProductsBase.xml");
                        XElement allVend = xDocument.Element("DEVICES").Elements("Vendor").FirstOrDefault(
                            i => i.FirstAttribute.Name.ToString().Contains(hexVendor));
                        var corpAttr = allVend.FirstAttribute;
                        corpName = corpAttr.Value;
                        //var vend = allVend.FirstOrDefault(i => i.FirstAttribute.Name.ToString().Contains(hexVendor));

                        var deviceAttr = xDocument.Element("DEVICES").Elements("Vendor");
                        foreach (XNode attr in deviceAttr.Nodes())
                        {
                            if (attr.ToString().Contains(hexProduct))
                            {
                                string[] s = attr.ToString().Split('=', '/');
                                joyName = s[1];
                                break;
                            }
                        }
                    } 
                    return joyName + " (" + corpName + ")";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return null;
                }
            }
            return null;
        }

        public static string ShowInformationAboutBase()
        {
            XDocument xDocument = XDocument.Load("VendorsAndProductsBase.xml");
            var allVend = xDocument.Element("DEVICES").Elements("BaseInf").FirstOrDefault();
            return allVend.FirstAttribute.Value;
        }
    }
}
