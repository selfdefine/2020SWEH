import React from 'react';
import { Button } from 'antd';
import SlideBar from './components/SlideBar'
import SwitchBar from './components/SwitchBar'
import SelectOperator from './components/SelectOperator'
import Subject from './components/Subject'
import generator from './util/generator'
import html2canvas from 'html2canvas'
import './App.css';

// 下载Canvas元素的图片
function downloadCanvasIamge (canvas, name) {
  // 通过选择器获取canvas元素
  // var canvas = document.querySelector(selector)
  // 使用toDataURL方法将图像转换被base64编码的URL字符串
  var url = canvas.toDataURL('image/png')
  // 生成一个a元素
  var a = document.createElement('a')
  // 创建一个单击事件
  var event = new MouseEvent('click')

  // 将a的download属性设置为我们想要下载的图片名称，若name不存在则使用‘下载图片名称’作为默认名称
  a.download = name || '下载图片名称'
  // 将生成的URL设置为a.href属性
  a.href = url

  // 触发a的单击事件
  a.dispatchEvent(event)
}

function doPrint3 () {

  //判断iframe是否存在，不存在则创建iframe
  // var iframe = document.getElementById("print-iframe");
  let iframe = 0
  if (!iframe) {
    var el = document.getElementsByClassName("body")[0];
    iframe = document.createElement('IFRAME');
    var doc = null;
    // iframe.setAttribute("id", "print-iframe");
    iframe.setAttribute('style', 'position:absolute;width:0px;height:0px;left:-500px;top:-500px;');
    document.body.appendChild(iframe);
    doc = iframe.contentWindow.document;
    // console.log(doc)
    //这里可以自定义样式
    doc.write(`
    <style type="text/css">
      .ant-row {
        display: -ms-flexbox;
        display: flex;
        -ms-flex-flow: row wrap;
        flex-flow: row wrap;
      }
      .ant-col-10 {
        display: block;
        -ms-flex: 0 0 41.66666667%;
        flex: 0 0 41.66666667%;
        max-width: 41.66666667%;
      }
      .ant-col {
          position: relative;
          max-width: 100%;
          min-height: 1px;
      }
     </style>
     `);

    doc.write(el.innerHTML);
    doc.close();
    iframe.contentWindow.focus();
  }
  iframe.contentWindow.print();
  if (navigator.userAgent.indexOf("MSIE") > 0) {
    document.body.removeChild(iframe);
  }

}

function download (filename, text) {
  var element = document.createElement('a');
  element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
  element.setAttribute('download', filename);

  element.style.display = 'none';
  document.body.appendChild(element);

  element.click();

  document.body.removeChild(element);
}

export default class App extends React.Component {
  constructor (props) {
    super(props)
    this.state = {
      amount: 10,
      maxNumer: 40,
      brackets: true,
      decimal: true,
      selected: ['+'],
      subjects: [],
      disabled: true,
    }
  }

  changeHas = (changed, key) => {
    this.setState({
      [key]: changed
    })
  }

  generate = () => {
    let settings = this.state
    if (settings.selected.length === 0) {
      this.setState({
        selected: ['+'],
      })
      settings.selected = ['+']
    }
    let subjects = []

    subjects = generator(settings)
    this.setState({
      subjects,
      disabled: false
    })
  }

  render () {
    return (
      <div >
        <div className='header'>
          <div className="left">
            <SlideBar text={'题目数量'} inputValue={this.state.amount} onChange={(value) => this.changeHas(value, 'amount')}></SlideBar>
            <SlideBar text={'设置最大数'} inputValue={this.state.maxNumer} onChange={(value) => this.changeHas(value, 'maxNumer')}></SlideBar>
            <SwitchBar text={'是否有括号'} onChange={(value) => this.changeHas(value, 'brackets')}></SwitchBar>
            <SwitchBar text={'是否有小数'} onChange={(value) => this.changeHas(value, 'decimal')}></SwitchBar>
          </div>
          <div className="right">
            <SelectOperator defaultValue={this.state.defaultValue} onChange={(value) => this.changeHas(value, 'selected')}></SelectOperator>
            <div>
              <Button type="primary" size="small" onClick={this.generate}>生成</Button>
            </div>
            <div>
              <Button disabled={this.state.disabled} type="primary" size="small" onClick={() => {
                doPrint3()
              }}>打印</Button>
            </div>
            <div>
              <Button disabled={this.state.disabled} type="primary" size="small" onClick={() => {
                html2canvas(document.getElementsByClassName('body')[0]).then(function (canvas) {
                  // document.body.appendChild(canvas);
                  downloadCanvasIamge(canvas, '四则运算')
                });
              }}>输出为图片</Button>
            </div>
            <div>
              <Button disabled={this.state.disabled} type="primary" size="small" onClick={() => {
                let text = ''
                this.state.subjects.map(d => {
                  text = text + d + "\n"
                  return d
                })
                download('四则运算', text)
              }}>输出为文件</Button>
            </div>
          </div>
        </div>
        <div className='body'>
          <Subject subjects={this.state.subjects} />
        </div>
      </div>
    );
  }
}
