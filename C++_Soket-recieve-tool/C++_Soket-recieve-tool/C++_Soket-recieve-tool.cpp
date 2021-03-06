// C++_Soket-recieve-tool.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;
using namespace std;
void main()
{
	boost::asio::io_service io_service;
	boost::asio::ip::udp::socket udp_socket(io_service);
	boost::asio::ip::udp::endpoint local_add(boost::asio::ip::address::from_string("192.168.192.5"), 19200);
	udp_socket.open(local_add.protocol());
	char receive_str[1024] = { 0 };
	while (1)
	{
		std::string s;
		cout << "请输入robokit_log_start,并按回车"<< endl;
		cin >> s;
		udp_socket.send_to(boost::asio::buffer(s.c_str(), s.size()), local_add);
		for (;;)
		{
			udp_socket.receive_from(boost::asio::buffer(receive_str, 1024), local_add);
			cout << "收到" << receive_str << endl;
			memset(receive_str, 0, 1024);
		}
	}
}

