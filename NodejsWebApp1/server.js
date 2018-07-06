'use strict';

var http = require('http');
var NodeClass = require('./test_class');

//var http = require('http');
//http.request({
//    protocol: 'https',
//    host: 'some-domain.com',
//    path: '/accounts/login/',
//    headers: { 'Cookie': 'crsftoken=xxxxxssometokenxxxxx' }
//});

// 1. ��û�� url�� ��ü�� ����� ���� url �����
var url = require('url');
// 2. ��û�� url �߿� Query String �� ��ü�� ����� ���� querystring ��� ���
var querystring = require('querystring');

function parseCookies(request) {
    var list = {},
        rc = request.headers.cookie;

    rc && rc.split(';').forEach(function (cookie) {
        var parts = cookie.split('=');
        list[parts.shift().trim()] = decodeURI(parts.join('='));
    });

    return list;
}

//var server = http.createServer(function (request, response) {

//    // 1. post�� ���޵� �����͸� ���� ������ ����
//    var postdata = '';
//    // 2. request��ü�� on( ) �Լ��� 'data' �̺�Ʈ�� ����
//    request.on('data', function (data) {
//        // 3. data �̺�Ʈ�� �߻��� ������ callback�� ���� postdata ������ ���� ����
//        postdata = postdata + data;
//    });

//    // 4. request��ü�� on( ) �Լ��� 'end' �̺�Ʈ�� ����
//    request.on('end', function () {
//        // 5. end �̺�Ʈ�� �߻��ϸ�(end�� �ѹ��� �߻��Ѵ�) 3������ �����ص� postdata �� querystring ���� ��üȭ
//        var parsedQuery = querystring.parse(postdata);
//        // 6. ��üȭ�� �����͸� �α׷� ���
//        console.log('parsedQuery:'+parsedQuery);
//        // 7. ���� HEADER �� �����͸� ��Ƽ� Ŭ���̾�Ʈ�� ����ó��
//        response.writeHead(200, {
//            'Content-Type': 'text/html',
//            'charset': 'utf-8',
//            'Set-Cookie': 'mycookie=test'
//        });
//        var result = parsedQuery.var1;
//        response.end('var1�� �� = ' + result);
//    });

//    var nodeClass = new NodeClass();
//    // setMessage �Լ��� ���� �Է��Ѵ�.
//    nodeClass.setMessage('Good to See u!');
//    // �Էµ� ���� ����Ѵ�.
//    console.log(nodeClass.getMessage());
//    console.log('--- log start1 ---');
//    var myClazz = new Clazz('see U!');
//    console.log(myClazz.msg);
//    //myClazz.print();
//    // 3. �ܼ�ȭ�鿡 �α� ���� �κ��� ���
//    console.log('--- log start ---');
//    // 4. ���������� ��û�� �ּҸ� parsing �Ͽ� ��üȭ �� ���
//    var parsedUrl = url.parse(request.url);
//    console.log(parsedUrl);
//    // 5. ��üȭ�� url �߿� Query String �κи� ���� ��üȭ �� ���
//    var parsedQuery = querystring.parse(parsedUrl.query, '&', '=');
//    console.log(parsedQuery);
//    var result1 = parsedQuery.var1;
//    console.log('���޵� var1�� ���� ' + result1 + '�Դϴ�');
//    // 6. �ܼ�ȭ�鿡 �α� ���� �κ��� ���
//    console.log('--- log end ---');

//    // To Read a Cookie
//    var cookies = parseCookies(request);
//    console.log(cookies);
//    // To Write a Cookie
//    response.writeHead(200, {
//        'Content-Type': 'text/html',
//        'charset':'utf-8',
//        'Set-Cookie': 'mycookie=test'
//    });
//    //response.end('Hello node.js!!');
//    response.end('var1:' + parsedQuery.var1);
//});

//server.listen(8080, function () {
//    //http://localhost:8080/?var1=newData&var2=153&var3=testdata2017
//    console.log('Server is running...2');
//});

var server = http.createServer(function (request, response) {
    // 1. post�� ���޵� �����͸� ���� ������ ����
    var postdata = '';
    // 2. request��ü�� on( ) �Լ��� 'data' �̺�Ʈ�� ����
    request.on('data', function (data) {
        // 3. data �̺�Ʈ�� �߻��� ������ callback�� ���� postdata ������ ���� ����
        postdata = postdata + data;
    });

    // 4. request��ü�� on( ) �Լ��� 'end' �̺�Ʈ�� ����
    request.on('end', function () {
        // To Read a Cookie
        var cookies = parseCookies(request);
        console.log(cookies);
        // 5. end �̺�Ʈ�� �߻��ϸ�(end�� �ѹ��� �߻��Ѵ�) 3������ �����ص� postdata �� querystring ���� ��üȭ
        var parsedQuery = querystring.parse(postdata);
        // 6. ��üȭ�� �����͸� �α׷� ���
        console.log(parsedQuery);
        // 7. ���� HEADER �� �����͸� ��Ƽ� Ŭ���̾�Ʈ�� ����ó��
        response.writeHead(200, {
            'Content-Type': 'text/html',
            'charset': 'utf-8',
            'Set-Cookie': 'mycookie=test'
        });
        response.end(
            'var1 = ' + parsedQuery.var1 +
            ' var2 = ' + parsedQuery.var2 +
            ' var3 = ' + parsedQuery.var3 +
            ' cookies = ' + cookies

            );
    });

});

server.listen(8080, function () {
    console.log('Server is running...');
});

function Clazz(msg) {
    this.name = 'I am Class';
    this.msg = msg;

    //msg2 = 'find me';
    //console.log('clazz:' + msg2)

    this.print = function () {
        console.log('this.print:'+msg2)
    }
}