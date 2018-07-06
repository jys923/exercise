using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// 빈 페이지 항목 템플릿에 대한 설명은 https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x412에 나와 있습니다.

namespace UWP_01
{
    /// <summary>
    /// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private void Button0_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {

        }

        const int GET = 0;
        const int POST = 1;
        async Task<string> HttpRequest(int RequestMethod, string url, Dictionary<string, string> valuePairs)
        {
            string result = "";
            using (HttpClient client = new HttpClient())
            {
                string Uri = url;
                client.BaseAddress = new Uri(Uri);
                if (RequestMethod == GET)
                {

                    FormUrlEncodedContent encodedContent = new FormUrlEncodedContent(valuePairs);
                    System.Diagnostics.Debug.WriteLine("HttpRequestGet.encodedContent:" + encodedContent.ReadAsStringAsync().Result);

                    Uri = Uri + "?" + encodedContent.ReadAsStringAsync().Result;
                    System.Diagnostics.Debug.WriteLine("HttpRequestGet.Uri:" + Uri);
                    HttpResponseMessage response = await client.GetAsync(Uri);
                    //will throw an exception if not successful
                    //response.EnsureSuccessStatusCode();
                    System.Diagnostics.Debug.WriteLine("HttpRequestGet.StatusCode:" + response.StatusCode);
                    if (response.StatusCode == HttpStatusCode.OK)
                    {
                        result = await response.Content.ReadAsStringAsync();
                        System.Diagnostics.Debug.WriteLine("HttpRequestGet:strResult" + result);
                    }
                    else
                    {
                        result = "err:" + response.StatusCode.ToString();
                    }
                }
                else if (RequestMethod == POST)
                {
                    FormUrlEncodedContent encodedContent = new FormUrlEncodedContent(valuePairs);
                    System.Diagnostics.Debug.WriteLine("HttpRequestPost.encodedContent:" + encodedContent.ReadAsStringAsync().Result);
                    System.Diagnostics.Debug.WriteLine("HttpRequestPost.Uri:" + Uri);
                    HttpResponseMessage response = await client.PostAsync(Uri, encodedContent);
                    //will throw an exception if not successful
                    //response.EnsureSuccessStatusCode();
                    System.Diagnostics.Debug.WriteLine("HttpRequestPost.StatusCode:" + response.StatusCode);
                    if (response.StatusCode == HttpStatusCode.OK)
                    {
                        result = await response.Content.ReadAsStringAsync();
                        System.Diagnostics.Debug.WriteLine("HttpRequestPost:strResult" + result);
                    }
                    else
                    {
                        result = "err:" + response.StatusCode.ToString();
                    }
                }
            }
            return result;
        }
    }
}
