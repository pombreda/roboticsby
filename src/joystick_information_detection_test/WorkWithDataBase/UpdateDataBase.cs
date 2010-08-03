using System;
using System.Collections.Generic;
using System.Xml.Linq;
using System.Windows;
using System.IO;
using Joystick_2008_To_WPF.BaseStructs;

namespace Joystick_2008_To_WPF.WorkWithDataBase
{
    class UpdateDataBase
    {
        public static void ToUpdateDataBase(IEnumerable<Vendor> vendors, IEnumerable<Product> products, string infAboutDatas)
        {
            try
            {
                var fileInfo = new FileInfo("VendorsAndProductsBase.xml");
                fileInfo.Delete();
                fileInfo.Create();
                var doc = new XDocument(new XDeclaration("1.0", "utf-8", "yes"));
                doc.Add(new XComment("Vendors And Products Base"));
                var devices = new XElement("DEVICES");
                var baseInf = new XElement("BaseInf");
                baseInf.Add(new XAttribute("inf", infAboutDatas));
                devices.Add(baseInf);
                foreach (var v in vendors)
                {
                    var readed = false;
                    var xElementV = new XElement("Vendor");
                    xElementV.Add(new XAttribute("v_" + v.VendorStr, v.Name));

                    foreach (var p in products)
                    {
                        var xElementP = new XElement("Product");
                        if (p.VendorId == v.VendorId)
                        {
                            readed = true;
                            xElementP.Add(new XAttribute("p_" + p.ProductStr, p.Name));
                            xElementV.Add(xElementP);
                        }
                        else if (readed)
                        {
                            break;
                        }
                    }
                    devices.Add(xElementV);
                }

                doc.Add(devices);
                doc.Save("VendorsAndProductsBase.xml");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }
        public static void GetDatasFromTxtFile(ref List<Vendor> vendors, ref List<Product> products, ref string infAboutBase)
        {
            using (var fs = new FileStream("VENDORS.txt", FileMode.Open, FileAccess.Read))
            {
                using (var str = new StreamReader(fs))
                {
                    string s;
                    var vendorId = new Guid();
                    #region Information about base
                    while ((s = str.ReadLine()) != null)
                    {
                        if (s == "# Vendors, devices and interfaces. Please keep sorted.")
                        {
                            break;
                        }
                        if ((!s.StartsWith("#")) || (s != ""))
                        {
                            infAboutBase += s + "\n";
                        }
                    }
                    #endregion
                    #region VENDORS PRODUCTS
                    while ((s = str.ReadLine()) != null)
                    {
                        if (s.StartsWith("\t"))
                        {
                            var inf = s.Split(new[] { '\t', ' ' }, 3);
                            var p = new Product(Guid.NewGuid(), inf[1], inf[2], vendorId);
                            products.Add(p);
                        }
                        else if ((!s.StartsWith("#")) && (s != ""))
                        {
                            vendorId = Guid.NewGuid();
                            var inf = s.Split(new[] { ' ' }, 2);
                            var v = new Vendor(vendorId, inf[0], inf[1]);
                            vendors.Add(v);
                        }
                    }
                    #endregion
                }
            }
        }
    }
}
