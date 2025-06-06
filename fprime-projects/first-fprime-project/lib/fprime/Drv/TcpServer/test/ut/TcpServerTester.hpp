// ======================================================================
// \title  TcpServer/test/ut/Tester.hpp
// \author mstarch
// \brief  hpp file for ByteStreamDriverModel test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "TcpServerGTestBase.hpp"
#include "Drv/TcpServer/TcpServerComponentImpl.hpp"
#include "Drv/Ip/TcpClientSocket.hpp"

#define SEND_DATA_BUFFER_SIZE 1024

namespace Drv {

  class TcpServerTester :
    public TcpServerGTestBase
  {
      // Maximum size of histories storing events, telemetry, and port outputs
      static const NATIVE_INT_TYPE MAX_HISTORY_SIZE = 1000;
      // Instance ID supplied to the component instance under test
      static const NATIVE_INT_TYPE TEST_INSTANCE_ID = 0;
      // Queue depth supplied to component instance under test
      static const NATIVE_INT_TYPE TEST_INSTANCE_QUEUE_DEPTH = 100;

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object TcpServerTester
      //!
      TcpServerTester();

      //! Destroy object TcpServerTester
      //!
      ~TcpServerTester();

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      void setup_helper(bool recv_thread, bool reconnect);

      //! Test basic messaging
      //!
      void test_basic_messaging();

      //! Test basic reconnection behavior
      //!
      void test_multiple_messaging();

      //! Test receive via thread
      //!
      void test_receive_thread();

      //! Test advanced (duration) reconnect
      //!
      void test_advanced_reconnect();

      // Helpers
      void test_with_loop(U32 iterations, bool recv_thread=false);
 
      void test_no_automatic_send_connection();

      void test_no_automatic_recv_connection();

      bool wait_on_change(bool open, U32 iterations);
      bool wait_on_started(bool open, U32 iterations);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_recv
      //!
      void from_recv_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &recvBuffer,
          const RecvStatus &recvStatus
      );

      //! Handler for from_ready
      //!
      void from_ready_handler(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Handler for from_allocate
      //!
      Fw::Buffer from_allocate_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 size
      );

      //! Handler for from_deallocate
      //!
      void from_deallocate_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &fwBuffer
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts();

      //! Initialize components
      //!
      void initComponents();

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      TcpServerComponentImpl component;
      Fw::Buffer m_data_buffer;
      U8 m_data_storage[SEND_DATA_BUFFER_SIZE];
      std::atomic<bool> m_spinner;

  };

} // end namespace Drv

#endif
