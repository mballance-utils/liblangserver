package org.liblangserver.tests;

import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

import org.eclipse.lsp4j.InitializeParams;
import org.eclipse.lsp4j.InitializeResult;
import org.eclipse.lsp4j.MessageActionItem;
import org.eclipse.lsp4j.MessageParams;
import org.eclipse.lsp4j.PublishDiagnosticsParams;
import org.eclipse.lsp4j.ShowMessageRequestParams;
import org.eclipse.lsp4j.services.LanguageClient;
import org.eclipse.lsp4j.services.LanguageServer;
import org.eclipse.lsp4j.services.TextDocumentService;
import org.eclipse.lsp4j.services.WorkspaceService;

public class Test {
	
	static class MyClient implements LanguageClient {

		@Override
		public void telemetryEvent(Object object) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void publishDiagnostics(PublishDiagnosticsParams diagnostics) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void showMessage(MessageParams messageParams) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public CompletableFuture<MessageActionItem> showMessageRequest(ShowMessageRequestParams requestParams) {
			System.out.println("showMessageRequest");
			return null;
		}

		@Override
		public void logMessage(MessageParams message) {
			System.out.println("logMessage");
		}
		
	}
	
	static class MyServer implements LanguageServer {

		@Override
		public CompletableFuture<InitializeResult> initialize(InitializeParams params) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public CompletableFuture<Object> shutdown() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void exit() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public TextDocumentService getTextDocumentService() {
			System.out.println("getTextDocumentService");
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public WorkspaceService getWorkspaceService() {
			// TODO Auto-generated method stub
			return null;
		}
	}
	
	public static final void main(String args[]) {
		MyClient client_i = new MyClient();
		TestClient client = new TestClient(client_i);
		
		int port = client.start_server();
		
		System.out.println("port=" + port);
		
		Runtime rt = Runtime.getRuntime();
		Process p = null;
		try {
			p = rt.exec(new String[] {
				"./tests/testlangserver",
				"-port",
				"" + port
			});
		} catch (IOException e) {
			
		}
	
		final InputStream stdin = p.getInputStream();
		Thread t = new Thread(new Runnable() {
			
			@Override
			public void run() {
				while (true) {
					try {
						byte data[] = new byte[1024];
						int sz = stdin.read(data, 0, data.length);
						if (sz > 0) {
							System.out.write(data, 0, sz);
						} else {
							break;
						}
					} catch (IOException e) {
						break;
					}
				}
				// TODO Auto-generated method stub
				
			}
		});
		t.start();
		

		System.out.println("--> connect");
		try {
			client.connect();
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("<-- connect");
		
		InitializeParams params = new InitializeParams();
	
		try {
			System.out.println("--> initialize");
			InitializeResult resp = client.getRemoteProxy().initialize(params).get();
			System.out.println("<-- initialize");
		} catch (ExecutionException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.exit(0);
//		MyServer server = new MyServer();
//		
//		Launcher<LanguageServer> client_l = LSPLauncher.createClientLauncher(
//				client, 
//				System.in, 
//				System.out);
//
//		InitializeParams params = new InitializeParams();
//		client_l.getRemoteProxy().initialize(params);
//		client_l.getRemoteProxy().initialize(params);
//		client_l.getRemoteProxy().getTextDocumentService();
//		client_l.startListening();
//		
	}

}
