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

// 1. 요청한 url을 객체로 만들기 위해 url 모듈사용
var url = require('url');
// 2. 요청한 url 중에 Query String 을 객체로 만들기 위해 querystring 모듈 사용
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

//    // 1. post로 전달된 데이터를 담을 변수를 선언
//    var postdata = '';
//    // 2. request객체에 on( ) 함수로 'data' 이벤트를 연결
//    request.on('data', function (data) {
//        // 3. data 이벤트가 발생할 때마다 callback을 통해 postdata 변수에 값을 저장
//        postdata = postdata + data;
//    });

//    // 4. request객체에 on( ) 함수로 'end' 이벤트를 연결
//    request.on('end', function () {
//        // 5. end 이벤트가 발생하면(end는 한버만 발생한다) 3번에서 저장해둔 postdata 를 querystring 으로 객체화
//        var parsedQuery = querystring.parse(postdata);
//        // 6. 객체화된 데이터를 로그로 출력
//        console.log('parsedQuery:'+parsedQuery);
//        // 7. 성공 HEADER 와 데이터를 담아서 클라이언트에 응답처리
//        response.writeHead(200, {
//            'Content-Type': 'text/html',
//            'charset': 'utf-8',
//            'Set-Cookie': 'mycookie=test'
//        });
//        var result = parsedQuery.var1;
//        response.end('var1의 값 = ' + result);
//    });

//    var nodeClass = new NodeClass();
//    // setMessage 함수로 값을 입력한다.
//    nodeClass.setMessage('Good to See u!');
//    // 입력된 값을 출력한다.
//    console.log(nodeClass.getMessage());
//    console.log('--- log start1 ---');
//    var myClazz = new Clazz('see U!');
//    console.log(myClazz.msg);
//    //myClazz.print();
//    // 3. 콘솔화면에 로그 시작 부분을 출력
//    console.log('--- log start ---');
//    // 4. 브라우저에서 요청한 주소를 parsing 하여 객체화 후 출력
//    var parsedUrl = url.parse(request.url);
//    console.log(parsedUrl);
//    // 5. 객체화된 url 중에 Query String 부분만 따로 객체화 후 출력
//    var parsedQuery = querystring.parse(parsedUrl.query, '&', '=');
//    console.log(parsedQuery);
//    var result1 = parsedQuery.var1;
//    console.log('전달된 var1의 값은 ' + result1 + '입니다');
//    // 6. 콘솔화면에 로그 종료 부분을 출력
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
    // 1. post로 전달된 데이터를 담을 변수를 선언
    var postdata = '';
    // 2. request객체에 on( ) 함수로 'data' 이벤트를 연결
    request.on('data', function (data) {
        // 3. data 이벤트가 발생할 때마다 callback을 통해 postdata 변수에 값을 저장
        postdata = postdata + data;
    });

    // 4. request객체에 on( ) 함수로 'end' 이벤트를 연결
    request.on('end', function () {
        // To Read a Cookie
        var cookies = parseCookies(request);
        console.log(cookies);
        // 5. end 이벤트가 발생하면(end는 한버만 발생한다) 3번에서 저장해둔 postdata 를 querystring 으로 객체화
        var parsedQuery = querystring.parse(postdata);
        // 6. 객체화된 데이터를 로그로 출력
        console.log(parsedQuery);
        // 7. 성공 HEADER 와 데이터를 담아서 클라이언트에 응답처리
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