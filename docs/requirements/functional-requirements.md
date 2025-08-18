# GerenciaLab - Functional Requirements Specification

## Table of Contents
1. [Objective](#objective)
2. [Product Description](#product-description)
3. [Functional Requirements](#functional-requirements)
4. [User Stories and Test Scenarios](#user-stories-and-test-scenarios)
5. [System Services](#system-services)
6. [User Interface Requirements](#user-interface-requirements)

## Objective

This document aims to describe, in a clear and structured manner, the functional requirements of the GerenciaLab system, a software developed to solve the main problems faced in patient care at clinical laboratory facilities. Through the automation of ticket issuance and queue control, queue organization, priority service management, and administrative report generation, the system seeks to significantly improve operational efficiency and user experience.

## Product Description

### Product Scope

#### Organizational Context
Currently, patient care control in clinical laboratories is performed manually through the physical delivery of paper tickets, without clear distinction between different types of exams or service priority. Patients form physical queues at the location and wait to be called according to arrival order, which frequently generates confusion, dissatisfaction, and delays, especially during peak hours. Additionally, there is no standardized system for organizing priority queues, such as for elderly, pregnant women, or people with disabilities. This lack of automation compromises service efficiency, increases waiting time, and impairs the overall patient experience.

#### What the Product Is
The product is a queue management system designed to optimize patient care in clinical laboratories, focusing on automatic organization of call order, prioritization of priority services (such as elderly, pregnant women, and people with disabilities), and categorization by type of exam to be performed.

It is expected that this system will automate the process of ticket issuance and control, facilitating patient flow management both at reception and in collection and analysis areas. The system should also offer a clear view of active tickets, as well as real-time queue progress monitoring by staff and patients.

#### Product Name and Main Components
GerenciaLab consists of three main modules that work in an integrated manner to optimize laboratory service:

- **LabFila** – Local service application installed at laboratory counters and rooms, responsible for issuing tickets, organizing queues, classifying exam types, and identifying priority services.

- **LabPainel** – Visual interface (electronic panel) for displaying ticket calls in real-time, highlighting service type, priority, and service location (room or counter).

- **LabRelatório** – Administrative reporting module, focused on generating statistical reports on average waiting time, service volume by exam type, and flow control by period.

#### Product Mission
Currently, laboratory service is performed in a disorganized and manual manner, with physical ticket distribution, lack of control over waiting time, and no clear distinction between priority and conventional patients. This process results in long queues, confusion in service order, and patient dissatisfaction, in addition to making internal service flow management difficult. Therefore, this product aims to organize and automate the process of ticket issuance and calling, categorizing services by exam type and priority, reducing waiting time, increasing team efficiency, and improving patient experience. In this way, the system aims to add value to the laboratory by enabling greater operational control, better use of human resources, and accurate measurement of performance indicators (KPIs), such as average waiting time, daily service volume, and user satisfaction index.

#### Product Boundaries
The queue and ticket management system will not perform advance exam scheduling through external channels (such as phone, website, or application), nor will it integrate directly with electronic medical record systems, billing, or medical insurance providers.

#### Product Benefits

**For Patients:**
- Significant reduction in waiting time, resulting from more agile and organized service flow
- Fair and transparent service, respecting legal priorities for elderly, pregnant women, and people with disabilities
- Greater clarity regarding call order and service location through electronic panels with visual and audio alerts
- More comfortable and less stressful experience, reducing the need to remain in physical queues for long periods

**For Receptionists and Attendants:**
- Simple and fast ticket issuance and service categorization by exam type and priority
- Process automation reduces workload related to manual queue organization
- Reduces occurrence of conflicts with patients, as service order becomes completely transparent

**For Laboratory Managers and Administrators:**
- Broad visibility into service performance through detailed reports and metrics
- Strategic view allows optimization of human resource allocation according to demand by exam type and time
- Contributes to reduction of operational costs and increase in overall efficiency

#### Services Offered by the Product
The system will be divided into services with distinct responsibilities, ensuring high cohesion and low coupling:

**Service 1 – Ticket Issuance**
Responsible for generating tickets based on exam type and priority (common or preferential), automatically organizing patients into separate queues.

**Service 2 – Call and Queue Organization**
Controls service order, prioritizing preferential tickets and directing patients to appropriate counters or rooms.

**Service 3 – Panel Display**
Presents call information on digital panels distributed throughout the laboratory, including ticket number, exam type, and service location.

## Functional Requirements

### Core System Services

#### 1. Queue and Ticket Management Service
- **Issue Ticket**: Generate tickets based on exam type and priority (common or preferential)
- **Organize Queue**: Automatically organize patients in separate queues respecting priority and arrival order
- **Call Next Ticket**: Select and call the next ticket according to defined priority
- **Consult Status**: Display all tickets waiting for service and those currently being served

#### 2. Service Information Display
- **Display Called Ticket**: Show on panel the ticket being called for service
- **Service Location**: Display the location (counter) where the patient should go
- **Audio and Visual Alerts**: Emit sounds and visual signals to alert patients about their calls
- **Waiting Time**: Display the time the patient has been waiting after receiving the ticket

#### 3. Authentication System
- **Login**: Allow users to log into the system using their credentials
- **Password Recovery**: Allow password recovery via code sending or reset link
- **Change Password**: Allow users to change their passwords after login to maintain security

#### 4. Access Control
- **User Blocking**: Block users after multiple incorrect login attempts or for administrative reasons
- **Access Logs**: Store records of accesses and actions performed for auditing and security
- **Define Permissions**: Configure permissions and access levels for different user profiles

#### 5. System Maintenance
- **Update Parameters**: Allow changing system configurations, such as call time and available exam types
- **Backup and Restoration**: Perform system data backup and allow restoration in case of failures
- **Monitor System and Hardware**: Monitor the operation of devices (kiosk, panels) and system to ensure stability
- **Diagnose and Fix Failures**: Identify and resolve operational and system problems to maintain operation

#### 6. User Management
- **Register User**: Allow creation of new users with basic information and access profile
- **Edit User**: Allow modification of data and permissions of existing users
- **Deactivate/Delete User**: Enable deactivation or removal of users who no longer use the system
- **List Users**: Display active and inactive users to facilitate administration
- **Reset Password**: Allow password reset for users who forgot their credentials

### User Interface Requirements

#### 1. Self-Service Kiosk
- **Layout**: Full-screen interface with large, clear buttons ideal for non-technical users
- **Features**:
  - List of available exam types
  - Option to mark priority service
  - "Generate Ticket" button
  - Automatic ticket printing with relevant information
  - Ticket registration in the system

#### 2. Call Display Panel
- **Display**: Full-screen display, preferably connected to a TV in the waiting room
- **Elements**:
  - Currently called ticket (highlighted)
  - Exam type
  - Priority indicator (e.g., red color or priority icon)
  - Call sound (optional)
  - List of next tickets in queue

#### 3. Receptionist Screen
- **Interface**: Clean interface focused on service efficiency
- **Features**:
  - View all tickets in queue, separated by priority and common
  - Call next ticket (respecting priority)
  - Finalize service
  - View waiting time indicators

#### 4. Reports Screen
- **Interface**: Administrative-focused interface
- **Features**:
  - Filter selection (by date, exam type, priority/common)
  - Data generation/export

### Data Management Requirements

#### Database Interface
- **Connection**: Local or remote database connection for storing and retrieving ticket information
- **Data Types**:
  - Issued tickets
  - Exam type
  - Priority
  - Arrival time
  - Completed services
  - Statistical data for administrative reports

#### Data Flow
- **Input Sources**:
  - User actions in self-service kiosk
  - Receptionist updates
  - Report generation by administrator
- **Output Destinations**:
  - Call display panel
  - Administrative reports
  - Queue visualization by receptionist

## User Stories and Test Scenarios

### 1. Ticket Issuance
**User Story**: As a common user, I want to issue a ticket at the kiosk to be served in the correct order and according to my priority.

**Test Scenario (BDD)**: Priority ticket issuance
- **Given** that the kiosk is available and the user selects the exam type and marks the priority service option
- **When** they confirm ticket issuance
- **Then** a priority ticket should be generated, printed, and registered in the system

### 2. Queue Organization and Calling
**User Story**: As an attendant, I want to call the next ticket so that users are served respecting priority.

**Test Scenario (BDD)**: Calling next priority ticket
- **Given** that there are common and priority tickets waiting for service
- **When** the attendant clicks "Call Next Ticket"
- **Then** the oldest priority ticket should be called first and the panel should update in real-time with the new call

### 3. Panel Display
**User Story**: As a patient in the waiting room, I want to see my ticket and service location on the panel to correctly go to the counter or room when called.

**Test Scenario (BDD)**: Ticket display on panel
- **Given** that a ticket was called by the receptionist
- **When** the panel is updated
- **Then** it should display the ticket number, exam type, service location, and emit audio and visual alerts to draw attention

### 4. System Authentication
**User Story**: As an attendant, I want to log into the system to have secure access to restricted functionalities.

**Test Scenario (BDD)**: Login with valid credentials
- **Given** that the user is on the login screen and provides valid credentials
- **When** they click "Enter"
- **Then** the system should grant access to functionalities according to the profile

## System Integration Requirements

### Hardware Interfaces
1. **Ticket Printing Interface**: Automatic sending of generated tickets to thermal or conventional printer
2. **TV Display Interface**: Communication with television or monitor via HDMI cable or wireless connection
3. **Receptionist Station Interface**: Computer with mouse and keyboard for system operation

### Software Interfaces
1. **Database System Interface**: Interface with database system for data storage and retrieval
2. **Call Panel Interface**: Integration interface between main system and call display panel

### Communication Protocols
- **Local Network**: System operates in local network environment
- **Real-time Updates**: Instant updates between system components
- **Data Synchronization**: Automatic synchronization between kiosk, receptionist screen, and display panel

## Performance Requirements

### Response Time
- **Ticket Generation**: Less than 3 seconds after exam selection
- **Panel Updates**: Real-time updates when tickets are called
- **Queue Management**: Immediate response to priority changes

### Capacity
- **Service Volume**: Handle at least 50 tickets per hour without performance degradation
- **Peak Hours**: Maintain performance during high-traffic periods
- **Concurrent Users**: Support multiple kiosks and receptionist stations simultaneously

## Security Requirements

### Access Control
- **User Authentication**: Secure login system for staff access
- **Permission Levels**: Different access levels for attendants and administrators
- **Session Management**: Secure session handling and automatic logout

### Data Protection
- **Patient Privacy**: No sensitive patient information displayed on public panels
- **Audit Logs**: Complete logging of all system actions for compliance
- **Data Integrity**: Protection against unauthorized data modification

## Compliance Requirements

### Legal Compliance
- **Priority Service Laws**: Compliance with Brazilian legislation on priority service (Law No. 10,048/2000)
- **Data Protection**: Compliance with LGPD (General Data Protection Law)
- **Accessibility**: Compliance with eMAG (Electronic Government Accessibility Model) guidelines

### Operational Compliance
- **Service Standards**: Maintain laboratory service quality standards
- **Performance Metrics**: Regular reporting on service efficiency and patient satisfaction
- **Continuous Improvement**: System updates based on operational feedback and requirements 