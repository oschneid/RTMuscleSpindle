%This software is released under the MIT License (MIT)
%
%Copyright (c) 2015 Oliver Schneider
%
%Permission is hereby granted, free of charge, to any person obtaining a copy
%of this software and associated documentation files (the "Software"), to deal
%in the Software without restriction, including without limitation the rights
%to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
%copies of the Software, and to permit persons to whom the Software is
%furnished to do so, subject to the following conditions:
%
%The above copyright notice and this permission notice shall be included in all
%copies or substantial portions of the Software.
%
%THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
%IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
%FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
%AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
%LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
%OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
%SOFTWARE.


function varargout = MuscleSpindleGUI(varargin)
% MUSCLESPINDLEGUI MATLAB code for MuscleSpindleGUI.fig
%      MUSCLESPINDLEGUI, by itself, creates a new MUSCLESPINDLEGUI or raises the existing
%      singleton*.
%
%      H = MUSCLESPINDLEGUI returns the handle to a new MUSCLESPINDLEGUI or the handle to
%      the existing singleton*.
%
%      MUSCLESPINDLEGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MUSCLESPINDLEGUI.M with the given input arguments.
%
%      MUSCLESPINDLEGUI('Property','Value',...) creates a new MUSCLESPINDLEGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before MuscleSpindleGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to MuscleSpindleGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help MuscleSpindleGUI

% Last Modified by GUIDE v2.5 18-Dec-2012 11:57:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @MuscleSpindleGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @MuscleSpindleGUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT




% --- DisplayErrorMessage
% --- Utility function for displaying an error dialogue
function DisplayErrorMessage(msg, title)
        if nargin < 2
            title = 'Error';
        end
        errordlg(msg, title,'modal');


% --- Executes just before MuscleSpindleGUI is made visible.
function MuscleSpindleGUI_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to MuscleSpindleGUI (see VARARGIN)

    % Choose default command line output for MuscleSpindleGUI
    global hRootFigure
    hRootFigure = hObject;
    handles.output = hObject;
    
    % Setup model connection constants
    handles.ModelName = 'MuscleSpindleGUIModel';
    % Check to make sure model exists
    if 4 ~= exist(handles.ModelName, 'file')
        %model doesn't exist
        DisplayErrorMessage(sprintf('The model %s.mdl cannot be found.',handles.ModelName));
    else
        %Connect to model
        simulinkLicenceAvailable = license('test','Simulink');
        if simulinkLicenceAvailable
            try
                % Load the simulink model
                handles.Model = load_system(handles.ModelName);
            catch err
                DisplayErrorMessage(err.message);
            end
        end
    end

    % Set up GUI state parameters
    handles.ModelRunning = false;
    set(handles.btnStop, 'Enable', 'off');
    set(handles.btnStart, 'Enable', 'on');
    
    
    % Set up line handles for axes
    handles.LineData = struct(...
                            'Name', '', ...
                            'BlockName',   '', ...
                            'BlockHandle', [], ...
                            'CallbackHandle', [], ...
                            'Line',  [], ...
                            'XData', [], ...
                            'YData', []  ...
                            );
    
    handles.AxisTimeSpan = 4; %in seconds
    handles.LineData(1).Name = 'PrimaryAfferent';
    handles.LineData(1).BlockName = sprintf('%s/PrimaryAfferentScope', handles.ModelName);
    handles.LineData(1).BlockHandle = get_param(handles.LineData(1).BlockName,'Handle');
    handles.LineData(1).Line = line('Parent', handles.axsPrimaryAfferent, 'XData', [], 'YData', []);
    handles.LineData(1).XData = [];
    handles.LineData(1).YData = [];
    set(handles.axsPrimaryAfferent, 'YLim', [-50, 450],...
                                    'XLim', [0, handles.AxisTimeSpan]);
    ylabel(handles.axsPrimaryAfferent, 'Firing Rate (pps)');
    xlabel(handles.axsPrimaryAfferent, 'Time (s)');
    
    handles.LineData(2).Name = 'SecondaryAfferent';
    handles.LineData(2).BlockName = sprintf('%s/SecondaryAfferentScope', handles.ModelName);
    handles.LineData(2).BlockHandle = get_param(handles.LineData(2).BlockName,'Handle');
    handles.LineData(2).Line = line('Parent', handles.axsSecondaryAfferent, 'XData', [], 'YData', []);
    handles.LineData(2).XData = [];
    handles.LineData(2).YData = [];
    set(handles.axsSecondaryAfferent, 'YLim', [-50, 450], 'XLim', [0, handles.AxisTimeSpan]);
    ylabel(handles.axsSecondaryAfferent, 'Firing Rate (pps)');
    xlabel(handles.axsSecondaryAfferent, 'Time (s)');
    
    handles.LineData(3).Name = 'Length';
    handles.LineData(3).BlockName = sprintf('%s/Model', handles.ModelName);
    handles.LineData(3).BlockHandle = get_param(handles.LineData(3).BlockName,'Handle');
    handles.LineData(3).Line = line('Parent', handles.axsLength, 'XData', [], 'YData', []);
    handles.LineData(3).XData = [];
    handles.LineData(3).YData = [];
    set(handles.axsLength, 'YLim', [0.5, 1.5], 'XLim', [0, handles.AxisTimeSpan]);
    ylabel(handles.axsLength, 'Length (L0)');
    xlabel(handles.axsLength, 'Time (s)');
    
    
    
    % Fusimotor drive
    handles.FusimotorDrive = struct(...
                            'Name', '',...
                            'BlockName', '',...
                            'Active', [], ...
                            'Drive', []...
                            );
    %Dynamic
    handles.FusimotorDrive(1).Name = 'Dynamic';
    handles.FusimotorDrive(1).BlockName = sprintf('%s/DynamicFD', handles.ModelName);
    handles.FusimotorDrive(1).Active = false;
    handles.FusimotorDrive(1).Drive = '70';
    set(handles.edtDynamicFusimotorDrive, 'String', handles.FusimotorDrive(1).Drive);
    %Active
    handles.FusimotorDrive(2).Name = 'Static';
    handles.FusimotorDrive(2).BlockName = sprintf('%s/StaticFD', handles.ModelName);
    handles.FusimotorDrive(2).Active = false;
    handles.FusimotorDrive(2).Drive = '70';
    set(handles.edtStaticFusimotorDrive, 'String', handles.FusimotorDrive(2).Drive);
    
    %Length handles
    handles.LengthBlockName = sprintf('%s/TargetLength', handles.ModelName);
    handles.LengthBlockHandle = get_param(handles.LengthBlockName,'Handle');
    
    %Length visualization
    handles.Length = 0.8; 
    [X,Y,Z] = cylinder(sin(0:pi/20:pi));
    handles.VisualizationSurfaceZ = Z;
    handles.hVisualizationSurface = surf(handles.axsVisualization, 0.5*X, 0.5*Y, -Z*handles.Length, zeros(length(Z)));
    set(handles.axsVisualization, 'CameraPosition', [0,-1,-1.5/2], 'XLim', [-1,1], 'YLim', [-1,1], 'ZLim', [-1.5, 0]);
    set(handles.hVisualizationSurface, 'FaceLighting', 'phong', 'FaceColor', 'interp', 'AmbientStrength', 0.5);    
    light('Position', [-1,-1,1], 'Style', 'infinite');
    zlabel(handles.axsVisualization, 'Length (L0)');
    colormap([1,0,0]);
    
    


    %GUI Update time
    handles.guiTimer = timer('period', 1.0/10);
    set(handles.guiTimer, 'ExecutionMode', 'fixedrate', 'BusyMode', 'drop');
    set(handles.guiTimer, 'timerfcn', @(x,y)UpdateGUI);
    
    %Setup mouse information
    handles.MouseDown = false;
    handles.MousePos = [0,0];
    set(hRootFigure, 'WindowButtonMotionFcn', @MouseMove);
    set(hRootFigure, 'WindowButtonDownFcn', @MouseDown);
    set(hRootFigure, 'WindowButtonUpFcn', @MouseUp);
    handles.TargetLength = handles.Length;
    handles.MinimumTargetLength = 0.8; %Rest Length
    handles.MaximumTargetLength = 1.4; %reasonable to keep the signals from maxing out
    %greyed out minimum/maximum area 
   
    handles.TargetLengthNeedsSetting = false; %do we set this equal to the length? 
    handles.TargetLengthLine = line('Parent', handles.axsVisualization,...
                                    'XData', [-1, 1],...
                                    'YData', [0, 0],...
                                    'ZData', [-handles.TargetLength, -handles.TargetLength]);
    
    
    % Update handles structure
    guidata(hObject, handles);
    
    
    DrawMuscleSpindleVisualization;


function UpdateGUI
	global hRootFigure
    handles = guidata(hRootFigure);
    
    for idx = 1:length(handles.LineData)
        thisLineHandle = handles.LineData(idx).Line;

        % Get the data currently being displayed on the axis
        xdata = get(thisLineHandle,'XData');
        ydata = get(thisLineHandle,'YData');
        n = length(handles.LineData(idx).XData);
        if n > 0
            
            endtime = handles.LineData(idx).XData(n);
            starttime = endtime-handles.AxisTimeSpan;
            
            
            newXData = [xdata(xdata>=starttime) endtime];
            newYData = [ydata(xdata>=starttime) handles.LineData(idx).YData(n)];
            set(thisLineHandle,...
                'XData',newXData,...
                'YData',newYData);
            handles.LineData(idx).XData = [];
            handles.LineData(idx).YData = [];
            set(get(thisLineHandle, 'Parent'), 'XLim', [max(0, starttime), max(handles.AxisTimeSpan, endtime)]);
        end
    end
    
    %get new Target Length and update the target length line
    if handles.MouseDown
        pos = get(handles.axsVisualization, 'Position');
        zlims = get(handles.axsVisualization, 'ZLim');
        
        bheight = pos(4);
        btop = pos(2) + pos(4);
        aheight = zlims(2)-zlims(1);
        
        handles.TargetLength = min(handles.MaximumTargetLength,...
                                max(handles.MinimumTargetLength,...
                                 abs(min(0, (handles.MousePos(2) - btop))/bheight*aheight)));
        set(handles.TargetLengthLine, 'ZData', [-handles.TargetLength, -handles.TargetLength]);
        SetLength(handles.TargetLength, handles);
    end
    
    guidata(hRootFigure, handles);
    
    DrawMuscleSpindleVisualization

function DrawMuscleSpindleVisualization
    global hRootFigure
    handles = guidata(hRootFigure);

    set(handles.hVisualizationSurface, 'ZData', -handles.VisualizationSurfaceZ*handles.Length);
    
%     [X,Y,Z] = cylinder(sin(0:pi/20:pi));
%     hSurface = surf(handles.axsVisualization, X, Y, -Z*handles.Length, zeros(length(Z)));
%     set(handles.axsVisualization, 'CameraPosition', [0,-1,-1.5/2], 'ZLim', [-1.5, 0]);
%     set(hSurface, 'FaceLighting', 'phong', 'FaceColor', 'interp', 'AmbientStrength', 0.5);    
%     light('Position', [-1,-1,1], 'Style', 'infinite');

function ToggleFusimotorDrive(idx)
    % idx   scalar index for the FusimotorDrive to toggle
    global hRootFigure
    handles = guidata(hRootFigure);
    
    handles.FusimotorDrive(idx).Active = ~handles.FusimotorDrive(idx).Active;
    guidata(hRootFigure, handles);
    
    SetFusimotorDrive(idx, handles)
    
    
    
function SetFusimotorDrive(idx, handles)
    % idx   scalar index for the FusimotorDrive to toggle
    global hRootFigure
    if nargin < 2
        handles = guidata(hRootFigure);
    end
    
    if handles.ModelRunning    
        if handles.FusimotorDrive(idx).Active
                set_param(handles.FusimotorDrive(idx).BlockName, 'Value', handles.FusimotorDrive(idx).Drive);
        else
                set_param(handles.FusimotorDrive(idx).BlockName, 'Value', '0');
        end 
    end
    
    guidata(hRootFigure, handles);
    
function SetLength(length, handles)
    % idx   scalar index for the FusimotorDrive to toggle
    global hRootFigure
    if nargin < 2
        handles = guidata(hRootFigure);
    end
    
    
    handles.Length = length;
    
    if handles.ModelRunning
                set_param(handles.LengthBlockName, 'Value', num2str(handles.Length));
    end
    
    guidata(hRootFigure, handles);



% --- Outputs from this function are returned to the command line.
function varargout = MuscleSpindleGUI_OutputFcn(hObject, eventdata, handles) 
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Get default command line output from handles structure
    varargout{1} = handles.output;


% --- Executes on button press in chkDynamicFusimotorDrive.
function chkDynamicFusimotorDrive_Callback(hObject, eventdata, handles)
    % hObject    handle to chkDynamicFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hint: get(hObject,'Value') returns toggle state of chkDynamicFusimotorDrive
    %disp(handles.foo);
    %handles.foo = handles.foo + 1;
    %guidata(hObject, handles);
    ToggleFusimotorDrive(1);
    



% --- Executes on button press in chkStaticFusimotorDrive.
function chkStaticFusimotorDrive_Callback(hObject, eventdata, handles)
    % hObject    handle to chkStaticFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hint: get(hObject,'Value') returns toggle state of chkStaticFusimotorDrive
    ToggleFusimotorDrive(2);


% --- Executes on slider movement.
function sldrDynamic_Callback(hObject, eventdata, handles)
    % hObject    handle to sldrDynamic (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'Value') returns position of slider
    %        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function sldrDynamic_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to sldrDynamic (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: slider controls usually have a light gray background.
    if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor',[.9 .9 .9]);
    end


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles)
    % hObject    handle to slider2 (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'Value') returns position of slider
    %        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider2_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to slider2 (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: slider controls usually have a light gray background.
    if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor',[.9 .9 .9]);
    end


% --- Executes on button press in btnStart.
function btnStart_Callback(hObject, eventdata, handles)
    % hObject    handle to btnStart (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    handles.ModelRunning = true;
    set(handles.btnStop, 'Enable', 'on');
    set(handles.btnStart, 'Enable', 'off');
    handles.TargetLengthNeedsSetting = true;
    for idx = 1:length(handles.LineData)
        set(handles.LineData(idx).Line, 'XData', [], 'YData', []);
        handles.LineData(idx).XData = [];
        handles.LineData(idx).YData = [];
    end
    guidata(hObject, handles);
    
    
    % set the stop time to inf
    set_param(handles.ModelName,'StopTime','inf');
    % set the simulation mode to normal
    set_param(handles.ModelName,'SimulationMode','normal');
    
    for idx = 1:length(handles.FusimotorDrive)
        SetFusimotorDrive(idx)
    end
    

    
    
    % Set up model callback's on model startup
    set_param(handles.ModelName,'StartFcn','SetupCallbacks');
    % start the model
    set_param(handles.ModelName,'SimulationCommand','start');
    
    %start the GUI Update timer
    start(handles.guiTimer);

    
%    disp(get_param(handles.modelName,'StartFcn'))

% --- Executes on button press in btnStop.
function btnStop_Callback(hObject, eventdata, handles)
    % hObject    handle to btnStop (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    StopModel();


function StopModel
    global hRootFigure
    handles = guidata(hRootFigure);
    stop(handles.guiTimer);
    set_param(handles.ModelName,'SimulationCommand','stop');
    handles.ModelRunning = false;
    set(handles.btnStart, 'Enable', 'on');
    set(handles.btnStop, 'Enable', 'off');
%    for idx = 1:length(handles.LineData)
%            delete(handles.LineData(idx).CallbackHandle);
%    end
    

function DisplayModelOutput(block, eventdata)
    global hRootFigure
    handles = guidata(hRootFigure);
   

    % Get the simulation time and the block data
    sTime = block.CurrentTime;
    data = block.InputPort(1).Data;
    
    idx = [handles.LineData.BlockHandle]==block.BlockHandle;
    
    
    handles.LineData(idx).XData = [handles.LineData(idx).XData sTime];
    handles.LineData(idx).YData = [handles.LineData(idx).YData data];
    
    if strcmp(handles.LineData(idx).Name, 'Length'); 
       handles.Length = data;
       if handles.TargetLengthNeedsSetting
           handles.TargetLengthNeedsSetting = false;
           handles.TargetLength = handles.Length;
           set(handles.TargetLengthLine, 'ZData', [-handles.TargetLength, -handles.TargetLength]);
       end
    end
    
    guidata(hRootFigure, handles);
    
    
        

    % Only the last 1001 points worth of data
    % The model sample time is 0.001 so this represents 1000 seconds of data
    %if length(xdata) < 1001
    %    newXData = [xdata sTime];
    %    newYData = [ydata data];
    %else
    %    newXData = [xdata(2:end) sTime];
    %    newYData = [ydata(2:end) data];
    %end


    % Display the new data set

    
function SetupCallbacks
    global hRootFigure
    handles = guidata(hRootFigure);
    
    for idx = 1:length(handles.LineData)
        handles.LineData(idx).CallbackHandle = add_exec_event_listener(handles.LineData(idx).BlockName, 'PostOutputs', @DisplayModelOutput);
    end
    
    guidata(hRootFigure, handles);

function b = HitBox(pos, box)
    x = pos(1);
    y = pos(2);
    
    bleft = box(1);
    bright = box(1) + box(3);
    bbottom = box(2);
    btop = box(2) + box(4);
    
    b = x > bleft && x < bright && y > bbottom && y < btop;
    
    
    
    
    
%
% Mouse Callbacks
%


% --- Executes on mouse press
function MouseMove(hObject, eventdata, handles)
    % hObject    handle
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    global hRootFigure
    handles = guidata(hRootFigure);
    handles.MousePos = get(hObject,'CurrentPoint');
    guidata(hRootFigure, handles);
    
% --- Executes on mouse press
function MouseDown(hObject, eventdata, handles)
    % hObject    handle
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    global hRootFigure
    handles = guidata(hRootFigure);
    if HitBox(handles.MousePos, get(handles.axsVisualization, 'Position'))
        handles.MouseDown = true;
    end
    guidata(hRootFigure, handles);
    
    % --- Executes on mouse up
function MouseUp(hObject, eventdata, handles)
    % hObject    handle
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    global hRootFigure
    handles = guidata(hRootFigure);
    handles.MouseDown = false;
    guidata(hRootFigure, handles);



function edtDynamicFusimotorDrive_Callback(hObject, eventdata, handles)
    % hObject    handle to edtDynamicFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of edtDynamicFusimotorDrive as text
    %        str2double(get(hObject,'String')) returns contents of edtDynamicFusimotorDrive as a double
    global hRootFigure
    handles = guidata(hRootFigure);
    handles.FusimotorDrive(1).Drive = get(hObject, 'String');
    guidata(hRootFigure, handles);
    
    SetFusimotorDrive(1);


% --- Executes during object creation, after setting all properties.
function edtDynamicFusimotorDrive_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to edtDynamicFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end



function edtStaticFusimotorDrive_Callback(hObject, eventdata, handles)
    % hObject    handle to edtStaticFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of edtStaticFusimotorDrive as text
    %        str2double(get(hObject,'String')) returns contents of edtStaticFusimotorDrive as a double
    global hRootFigure
    handles = guidata(hRootFigure);
    handles.FusimotorDrive(2).Drive = get(hObject, 'String');
    guidata(hRootFigure, handles);
    
    SetFusimotorDrive(2);


% --- Executes during object creation, after setting all properties.
function edtStaticFusimotorDrive_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to edtStaticFusimotorDrive (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
    % hObject    handle to figure1 (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    if handles.ModelRunning
        StopModel();
    end
    % Hint: delete(hObject) closes the figure
    delete(hObject);
