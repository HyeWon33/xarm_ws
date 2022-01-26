
"use strict";

let SetDigitalIO = require('./SetDigitalIO.js')
let GetInt32 = require('./GetInt32.js')
let SetAxis = require('./SetAxis.js')
let MoveAxisAngle = require('./MoveAxisAngle.js')
let SetFloat32 = require('./SetFloat32.js')
let SetInt16 = require('./SetInt16.js')
let GripperMove = require('./GripperMove.js')
let MoveVelo = require('./MoveVelo.js')
let SetLoad = require('./SetLoad.js')
let ConfigToolModbus = require('./ConfigToolModbus.js')
let GetDigitalIO = require('./GetDigitalIO.js')
let MoveVelocity = require('./MoveVelocity.js')
let GetAnalogIO = require('./GetAnalogIO.js')
let TCPOffset = require('./TCPOffset.js')
let SetMultipleInts = require('./SetMultipleInts.js')
let SetString = require('./SetString.js')
let GetControllerDigitalIO = require('./GetControllerDigitalIO.js')
let Move = require('./Move.js')
let SetControllerAnalogIO = require('./SetControllerAnalogIO.js')
let SetToolModbus = require('./SetToolModbus.js')
let GetErr = require('./GetErr.js')
let ClearErr = require('./ClearErr.js')
let PlayTraj = require('./PlayTraj.js')
let GetFloat32List = require('./GetFloat32List.js')
let GripperState = require('./GripperState.js')
let GripperConfig = require('./GripperConfig.js')

module.exports = {
  SetDigitalIO: SetDigitalIO,
  GetInt32: GetInt32,
  SetAxis: SetAxis,
  MoveAxisAngle: MoveAxisAngle,
  SetFloat32: SetFloat32,
  SetInt16: SetInt16,
  GripperMove: GripperMove,
  MoveVelo: MoveVelo,
  SetLoad: SetLoad,
  ConfigToolModbus: ConfigToolModbus,
  GetDigitalIO: GetDigitalIO,
  MoveVelocity: MoveVelocity,
  GetAnalogIO: GetAnalogIO,
  TCPOffset: TCPOffset,
  SetMultipleInts: SetMultipleInts,
  SetString: SetString,
  GetControllerDigitalIO: GetControllerDigitalIO,
  Move: Move,
  SetControllerAnalogIO: SetControllerAnalogIO,
  SetToolModbus: SetToolModbus,
  GetErr: GetErr,
  ClearErr: ClearErr,
  PlayTraj: PlayTraj,
  GetFloat32List: GetFloat32List,
  GripperState: GripperState,
  GripperConfig: GripperConfig,
};
