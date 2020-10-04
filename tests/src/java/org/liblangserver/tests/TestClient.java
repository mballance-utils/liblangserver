package org.liblangserver.tests;

import java.net.ServerSocket;
import java.net.Socket;

import org.eclipse.lsp4j.jsonrpc.Launcher;
import org.eclipse.lsp4j.launch.LSPLauncher;
import org.eclipse.lsp4j.services.LanguageClient;
import org.eclipse.lsp4j.services.LanguageServer;

public class TestClient {
	
	public TestClient(LanguageClient client) {
		m_client = client;
		
	}
	
	public int start_server() {
		try {
			m_srv_sock = new ServerSocket(0);
			m_port = m_srv_sock.getLocalPort();
		} catch (Exception e) {
			e.printStackTrace();
			return -1;
		}
		
		return m_port;
	}
	
	void connect() throws Exception {
		System.out.println("--> accept");
		m_sock = m_srv_sock.accept();
		System.out.println("<-- accept");
		m_client_launcher = LSPLauncher.createClientLauncher(
				m_client, 
				m_sock.getInputStream(),
				m_sock.getOutputStream());
		m_client_launcher.startListening();
	}
	
	LanguageServer getRemoteProxy() {
		return m_client_launcher.getRemoteProxy();
	}

	private ServerSocket				m_srv_sock;
	private	Socket						m_sock;
	private int							m_port;
	private LanguageClient				m_client;
	private Launcher<LanguageServer>	m_client_launcher;

}
